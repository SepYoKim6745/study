import numpy as np
from function import sigmoid, softmax, cross_entropy_error
from util import im2col
from collections import OrderedDict
class Relu :
    def __init__(self) :
        self.mask = None
    
    def forward(self, x) :
        self.mask = (x<=0)
        out = x.copy()
        out[self.mask] = 0
        
        return out
    
    def backward(self, dout) :
        dout[self.mask] = 0
        dx = dout
        return dx
    
class Sigmoid :
    def __init__(self) :
        self.out = None
    
    def forward(self, x) :
        out = sigmoid(x)
        self.out = out
        return out
    
    def backward(self, dout) :
        dx = dout * (1.0 - self.out) * self.out
        return dx
    
class Affine :
    def __init__(self, W, b):
        self.W = W
        self.b = b
        self.x = None
        self.dW = None
        self.db = None
        
    def forward(self, x) :
        self.x = x
        out = np.dot(x, self.W) + self.b
        return out
    
    def backward(self, dout) :
        dx = np.dot(dout, self.W.T)
        self.dw = np.dot(self.x.T, dout)
        self.db = np.sum(dout, axis=0)
        
        return dx
    
class SoftmaxWithLoss :
    def __init__(self) :
        self.loss = None
        self.y = None
        self.t = None

    def forward(self, x, t) :
        self.t = t
        self.y = softmax(x)
        self.loss = cross_entropy_error(self.y, self.t)
    
    def backward(self, dout = 1) :
        batch_size = self.t.shape[0]
        dx = (self.y - self.t) / batch_size

        return dx
    
class Convolution :
    def __init__(self, W, b, stride=1, pad=0) :
        self.W = W
        self.b = b
        self.stride = stride
        self.pad = pad

    def forward(self, x) :
        FN, C, FH, FW = self.W.shape
        N, C, H, W = x.shape
        out_h = 1 + ((H + 2 * self.pad - FH) / self.stride)
        out_w = 1 + ((W + 2 * self.pad - FW) / self.stride)

        col = im2col(x, FH, FW, self.stride, self.pad)
        col_W = self.W.reshape(FN, -1).T
        out = np.dot(col, col_W) + self.b
        
        out = out.reshape(N, out_h, out_w, -1).transpose(0, 3, 1, 2)

        return 0

class Pooling:
    def __init__(self, pool_h, pool_w, stride=1, pad=0) :
        self.pool_h = pool_h
        self.pool_w = pool_w
        self.stride = stride
        self.pad = pad

    def forward(self, x) :
        N, C, H, W = x.shape
        out_h = int(1+ (H - self.pool_h) / self.stride)
        out_w = int(1+ (W - self.pool_w) / self.stride)

        col = im2col(x, self.pool_h, self.pool_w, self.stride, self.pad)
        col = col.reshape(-1, self.pool_h * self.pool_w)

        out  = np.max(col, axis = 1)

        out = out.reshape(N, out_h, out_w, C).transpose(0, 3, 1 ,2)
        
        return out
    

class SimpleConvNet :
    def __init__(self, input_dim=(1, 28, 28),
                 conv_param={'filter_num' : 30, 'filter_size' : 5, 'pad' : 0, 'stride':1},
                 hidden_size=100, output_size=10, weight_init_std=0.01):
        
        filter_num = conv_param['filter_num']
        filter_size = conv_param['filter_size']  
        filter_pad = conv_param['pad']
        filter_stride = conv_param['stride']
        input_size = input_dim[1]
        conv_output_size = (input_size - filter_size + 2*filter_pad) / filter_stride + 1
        pool_output_size = int(filter_num * (conv_output_size/2) * (conv_output_size/2))

        self.params = {}
        self.params['W1'] = weight_init_std * np.random.randn(filter_num, input_dim[0], filter_size, filter_size)
        self.params['b1'] = np.zeros(filter_num)
        self.params['W2'] = weight_init_std * np.random.randn(pool_output_size, hidden_size)
        self.params['b2'] = np.zeros(hidden_size)
        self.params['W3'] = weight_init_std * np.random.randn(hidden_size, output_size)
        self.params['b3'] = np.zeros(output_size)
        

        self.layers = OrderedDict()
        self.layers['Conv1'] = Convolution(self.params['W1'],
                                           self.params['b1'],
                                           conv_param['stride']
                                           conv_param['pad'])
        self.layers['Relu1'] = Relu()
        self.layers['Pool1'] = Pooling(pool_h=, pool_w=2, stride=2)
        self.layers['Affine1'] = Affine(self.params['W2'], self.params['b2'])
        self.layers['Relu2'] = Relu()
        self.layers['Affine2'] = Affine(self.params['W3'], self.params['b3'])

        self.last_layer = SoftmaxWithLoss()

    def predict(self, x) :
        for layer in self.layers.values() :
            x = layer.forward(x)
        return x

    def loss(self, x, t) :
        y = self.predict(x)
        return self.last_layer.forward(y, t)
    
    def gradient(self, x, t) :
        self.loss(x, t)

        dout = 1
        dout = self.last_layer.backward(dout)
        layers = list(self.layers.values())
        layers.reverse()
        for layer in layers :
            dout = layer.backward(dout)

        
        grads = {}
        grads['W1'] = self.layers['Conv1'].dW
        grads['b1'] = self.layers['Conv1'].db
        grads['W2'] = self.layers['Affine1'].dW
        grads['b2'] = self.layers['Affine1'].db
        grads['W3'] = self.layers['Affine2'].dW
        grads['b3'] = self.layers['Affine2'].db

        return grads



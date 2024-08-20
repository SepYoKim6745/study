import sys, os
sys.path.append(os.pardir)
import numpy as np
import matplotlib.pylab as plt
from common.function import numerical_diff;

def function_1 (x) :
    return 0.01*x**2 + 0.1*x

x = np.arange(0.0, 20.0, 0.1)
y = function_1(x)
plt.xlabel('x')
plt.ylabel('f(x)')
plt.plot(x, y)
plt.show()

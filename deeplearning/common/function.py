import numpy as np

#오차제곱합 (손실함수)
def sum_sqares_error(y, t) :
    return 0.5 * np.sum((y-t)**2)

#배치용 교차 엔트로피 오차(손실 함수)
def cross_entropy_error_1(y, t) :
    if y.ndim == 1 : 
         t = t.reshape(1, t.size)
         y = y.reshape(1, y.size)

    batch_size = y.shape[0]
    return -np.sum(t * np.log(y + 1e-7)) / batch_size

#배치용 교차 엔트로피 오차(손실 함수)
#정답레이블이 원-핫 인코딩 방식이 아닌 '7', '2'와 같은 경우
def cross_entropy_error_2(y, t) :
    if y.ndim == 1 :
        t = t.reshape(1, t.size)
        y = y.reshape(1, y.size)
    
    batch_size = y.shape[0]
    return -np.sum(np.log(y[np.arange(batch_size), t] + 1e-7)) / batch_size
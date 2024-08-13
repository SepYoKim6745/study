import numpy as np

#오차제곱합 (손실함수)
def sum_sqares_error(y, t) :
    return 0.5 * np.sum((y-t)**2)

def cross_entropy_error(y, t) :
    delta = 1e-7
    return -np.sum(t*np.log(y+delta))



import sys, os
import numpy as np
sys.path.append(os.pardir)
from common.function import numerical_diff

def function_2(x) :
    return x[0]**2 + x[1]**2

def function_tmp2(x) :
    print(x*x+4.0**2.0)
    return x*x + 4.0**2.0

print(numerical_diff(function_tmp2, 3.0))
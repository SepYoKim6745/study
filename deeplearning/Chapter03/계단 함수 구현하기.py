import numpy as np

def step_function(x) :
    if x > 0 :
        return 1
    else :
        return 0
    
# 개선된 step_function()
def step_function1(x) :
    y = x > 0
    return y.astype(np.int) #astype()은 열의 요소의 dtype을 변경하는 함수


x = np.array([-1.0, 1.0, 2.0])
y = x > 0
y = y.astype(np.int64)
print(y)

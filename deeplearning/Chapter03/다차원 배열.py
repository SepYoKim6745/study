import numpy as np

#1차원 배열 생성
# A = np.array([1, 2, 3, 4])
# print(A)
# print(np.ndim(A)) #ndim() 배열의 차원수 확인하는 함수
# print(A.shape)
# print(A.shape[0])

#2차원 배열 생성
# B = np.array([[1,2], [3,4], [5,6]])
# print(B)
# print(np.ndim(B))
# print(B.shape)

#행렬의 곱
# A = np.array([[1, 2], [3, 4]])
# print(A.shape)
# B = np.array([[5, 6], [7, 8]])
# print(B.shape)
# print(np.dot(A, B))

# A = np.array([[1,2,3], [4,5,6]])
# print(A.shape)
# B = np.array([[1,2], [3,4], [5,6]])
# B.shape
# np.dot(A,B)

#행렬의 곱 주의 사항(차원의 수 일치)
A = np.array([[1,2], [3,4], [5,6]])
print(A.shape)
B = np.array([7,8])
print(B.shape)

print(np.dot(A, B))
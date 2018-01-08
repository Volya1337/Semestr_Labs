from random import random

A = [0,0,0,0,0,0,0,0,0]
B = [0,0,0,0,0,0,0,0,0]
C = [0,0,0,0,0,0,0,0,0]
i = int(0)
j = int(0)
k = int(0)
n = int(0)
buf = int(0)
for i in range(9):
    A[i] = int(random() * (8)) + 1
    print('A=' + str(A[i]))
    B[i] = int(random() * (8)) + 1
    print('B=' + str(B[i]))

for k in range(3):
    for j in range(3):
        C[k * 3 + j] = 0
        for i in range(3):
            C[k * 3 + j] += A[k * 3 + i] * B[i * 3 + j]

for i in range(0, 9, 3):
    print(C[i], C[i+1], C[i+2])

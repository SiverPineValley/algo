import numpy as np

import random
random.seed(1)
np.random.seed(1)

def generate_3D_map(m):
    array = np.zeros((m,m,m))
    for i in range(m):
        for j in range(m):
            for k in range(m):
                array[i][j][k] = np.random.choice([0,1],p=[.9,.1])
    return array


# z, x, y
def coin_collect_3D(array):

    l = len(array)
    m = len(array[0])
    n = len(array[0][0])

    temp = np.zeros((l, m, n))
    temp[0][0][0] = array[0][0][0]

    # 각 z에 따른 첫 행과 열을 초기화한다.
    for z in range(l):
    	if z != 0:
    		temp[z][0][0] = temp[z-1][0][0] + array[z][0][0]
    		for x in range(m):
    			if x != 0:
    				temp[z][x][0] = max( temp[z][x-1][0], temp[z-1][x][0] ) + array[z][x][0]
    		for y in range(n):
    			if y != 0:
    				temp[z][0][y] = max( temp[z][0][y-1], temp[z-1][0][y] ) + array[z][0][y]
    	else:
    		for x in range(m):
    			if x != 0:
    				temp[0][x][0] = temp[0][x-1][0] + array[0][x][0]
    		for y in range(n):
    			if y != 0:
    				temp[0][0][y] = temp[0][0][y-1] + array[0][0][y]

    # 나머지를 구한다.
    for z in range(l):
    	for x in range(1,m):
    		for y in range(1,n):
    			if z != 0:
    				temp[z][x][y] = max(temp[z-1][x][y], temp[z][x-1][y], temp[z][x][y-1]) + array[z][x][y]
    			else:
    				temp[z][x][y] = max(temp[0][x-1][y], temp[0][x][y-1]) + array[0][x][y]

    return int(temp[-1][-1][-1])



A = generate_3D_map(6)
B = generate_3D_map(10)

print(coin_collect_3D(A))
print(coin_collect_3D(B))


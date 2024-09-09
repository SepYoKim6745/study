from collections import deque

dy = [2, 1, -1, -2, -2, -1, 1, 2]
dx = [1, 2, 2, 1, -1, -2, -2, -1]
cnt = 0 
tc = int(input())

for _ in range(tc) :
    l = int(input())
    visited = [[ 0 for j in range(l)] for i in range(l)]
    y, x = map(int, input().split())
    ey, ex = map(int, input().split())

    q = deque()
    q.append((y, x))
    visited[y][x] = 1
    while q :
        y, x = q.popleft()
        if y == ey and x == ex : break
        
        for idx in range(8) :
            ny = y + dy[idx]
            nx = x + dx[idx]

            if 0<=ny<l and 0<=nx<l :
                if visited[ny][nx] == 0 :
                    visited[ny][nx] = 1
                    q.append((ny, nx))
                cnt += 1
    
    print(cnt)
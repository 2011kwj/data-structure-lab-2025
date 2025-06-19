# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0

    #여기에서부터 코드를 작성하세요.
    from collections import deque

    def bfs(forest, N, x, y, size):
        visited = [[False]*N for _ in range(N)]
        q = deque()
        q.append((x, y, 0))
        visited[x][y] = True
        edible = []

        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        while q:
            cx, cy, dist = q.popleft()
            for d in range(4):
                nx, ny = cx + dx[d], cy + dy[d]
                if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                    if forest[nx][ny] <= size:
                        visited[nx][ny] = True
                        q.append((nx, ny, dist + 1))
                        if 0 < forest[nx][ny] < size:
                            edible.append((dist + 1, nx, ny))
        edible.sort()
        return edible

    while True:
        targets = bfs(forest, N, bear_x, bear_y, bear_size)
        if not targets:
            break

        dist, tx, ty = targets[0]
        time += dist
        honeycomb_count += 1
        forest[tx][ty] = 0
        bear_x, bear_y = tx, ty

        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0

    result = time
    print(result)
    return result

result = problem3(input)

assert result == 14
print("정답입니다.")

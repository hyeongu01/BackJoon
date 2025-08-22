# backjoon 2738 - 행렬 덧셈
# https://www.acmicpc.net/problem/2738

# 입력 부분
n, m = map(int, input().split())
matrix1 = []
matrix2 = []

for _ in range(n):
    matrix1.append(list(map(int, input().split())))

for _ in range(n):
    matrix2.append(list(map(int, input().split())))

# 문제풀이 부분
def list_add(list1, list2):
    return list(map(lambda a, b: a + b, list1, list2))

result = list(map(list_add, matrix1, matrix2))

# 결과 출력 부분
for line in result:
    for num in line:
        print(num, end=" ")
    print()

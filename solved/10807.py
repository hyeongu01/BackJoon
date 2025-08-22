# backjoon 10807 - 개수 세기
# https://www.acmicpc.net/problem/10807

_ = int(input())
numbers = list(map(int, input().split()))
v = int(input())

print(numbers.count(v))
num = int(input())

for i in range(num):
    A,B = map(int, input().split())   # map(함수, 반복 가능한 객체)
    print(A+B)
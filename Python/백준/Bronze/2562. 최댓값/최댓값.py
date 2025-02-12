num = []
for i in range(9):
    num.append(int(input()))
a = max(num)
print(a)
print(num.index(a)+1)
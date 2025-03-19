input()
a = [int(i) for i in input().split()]
a.sort()
m = 0
if len(a)%2 == 1:
    m = a.pop(-1)
b = [a[i] + a[-i-1] for i in range(len(a)//2)]
b.append(m)
print(max(b))
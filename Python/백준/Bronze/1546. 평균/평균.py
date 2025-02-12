t = int(input())
num = list(map(int, input().split())) 
    
a = max(num)

for i in range(0,t):
    num[i] = num[i]/a*100
    
print(sum(num)/t)
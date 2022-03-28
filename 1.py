# x,y,z = map(int,input().split())
# print(x,y,z)

# n = int(input())
# l  = [[int(j) for j in input().split()]for i in range(n)]
# # l = [int(x) for x in input().split()]
# print(l)


s1 = input()
s = s1
l,r = 0,len(s)-1
while(l<=r):
    s[l],s[r] = s[r] , s[l]
    l+=1
    r-=1
    if(s[l]=='@' or s[l]=='#' or s[l]=='$'):
        l+=1
    if(s[r]=='@' or s[r]=='#' or s[r]=='$'):
        r-=1
print(s)        

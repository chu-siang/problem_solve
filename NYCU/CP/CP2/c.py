#	Generalized Recursive Functions
n = int(input())
for _ in range(n):
    *np,c,d = [int(_) for _ in input().split()]
    A = np[::2]
    B = np[1::2]
    dp = {} # dict also can write dp = dict()
    
    def f(x,y):
        if x <= 0 or y <= 0:
            return d
        if (x,y) in dp:
            return dp[(x,y)]
        res = c
        for a,b in zip(A,B):
            res += f(x-a,y-b)
        dp[(x,y)] = res
        return res
    xy = [int(v) for v in input().split()]
    X = xy[::2]
    Y = xy[1::2]
    for [x,y] in zip(X,Y): # its okay without '['x,y']' so we can write x,y instead of [] 
        print(f(x,y))
    print()
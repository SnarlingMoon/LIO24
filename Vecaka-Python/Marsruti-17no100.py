rank = []
parent = []
def find(x):
        if (parent[x] != x):
            parent[x] = find(parent[x])
        return parent[x]

def join(x, y):
        xset = find(x)
        yset = find(y)
        if xset == yset:
            return
 
        if rank[xset] < rank[yset]:
            parent[xset] = yset
        elif rank[xset] > rank[yset]:
            parent[yset] = xset
        else:
            parent[yset] = xset
            rank[xset] = rank[xset] + 1

N, M = map(int, input().split())

rank = [1] * (N+1)
parent = [i for i in range(N+1)]

for i in range(N-1):
    a, b = map(int, input().split())

    if a!=1 and b!=1:
        join(a,b)

for i in range(M):
    a, b = map(int, input().split())
    if find(a)==find(b):
        print(0)
    else:
        print(1)

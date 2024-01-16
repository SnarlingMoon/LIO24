from heapq import heappush, heappop

K, M, N = map(int, input().split())

lst = []
out = []
inp = map(int, input().split())

for cand in inp:
    if cand >= M:
        if len(lst)<K:
            heappush(lst,cand)
            out.append(cand)
        elif len(lst)==K:
            if lst[0]<cand:
                heappop(lst)
                heappush(lst,cand)
                out.append(cand)
print(len(out))
print(*out)

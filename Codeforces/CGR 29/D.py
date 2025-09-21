import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda x: sys.stdout.write(str(x) + '\n')
for _ in range(int(input())) :
    n = int(input())
    a = list(map(int, input().split()))
    s = sum([i // 2 for i in a])
    a.sort()
    a.append(-1)
    c = []
    p = 0
    for i in range(1, n + 1):
        if (a[i] != a[i - 1]) :
            if (a[p] & 1) : 
                c.append(i - p)
            p = i
    c.sort(reverse= True)
    for i in range(0, len(c), 2):
        s += c[i]
    print(f"{s} {sum(a)+1-s}")
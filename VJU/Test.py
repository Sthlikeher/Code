import sys
input = lambda: sys.stdin.buffer.read().rstrip()
print = lambda x: sys.stdout.write(str(x) + '\n')
it = iter(sys.stdin.buffer.read().rstrip())
t = int(next(it))
out = []
for _ in range(t):
    n = int(next(it))
    cnt = {}
    ok = False
    for _ in range(n): 
        x = int(next(it))
        cnt[x] = cnt.get(x, 0) + 1
        if cnt[x] >= 2:
            ok = True
    out.append("YES" if ok else "NO")
print(out)
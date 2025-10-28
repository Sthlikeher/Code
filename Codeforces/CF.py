import sys
input = lambda: sys.stdin.buffer.readline().rstrip()
print = lambda x: sys.stdout.write(str(x) + '\n')
def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    t = next(it)
    ot = []
    for _ in range(t):
        n = next(it); k = next(it)
        a = [next(it) for _ in range(n)]
        f = [0] * (n + 1)
        for x in a:
            if 1 <= x <= n:
                f[x] += 1
        p = [0] * (n + 1)
        for i in range(1, n + 1):
            p[i] = p[i - 1] + f[i]
        res = 1
        for g in range(n, 0, - 1):
            up = min(n , 4 * g - 1)
            s1 = p[up]
            s2 = 0
            if (g <= n):
                s2 += f[g]
            if 2 * g <= n:
                s2 += f[2 * g]
            if 3 * g <= n:
                s2 += f[3 * g]
            bad = s1 - s2
            if bad <= k:
                res = g
                break  
        print(res)
if __name__ == "__main__":
    main()
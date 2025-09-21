import sys
input = lambda: sys.stdin.readline().rstrip()
# print = lambda x: sys.stdout.write(str(x) + '\n')
def solve() :
    t = int(input())
    for _ in range(t) :
        l, r = map(int, input().split())
        n = r - l + 1
        a = list(range(n))
        maxbit = (r.bit_length() - 1) if r > 0 else 0
        for k in range(maxbit, -1, -1) :
            block = 1 << (k + 1)
            half = 1 << k
            for L in range(0, n, block) :
                R = min(n, L + block)
                seg = a[L:R]
                o = [x for x in seg if (x >> k) & 1]
                zs = [x for x in seg if not ((x >> k) & 1)]
                length = R - L
                len1 = min(half, length)
                to1 = min(len(o), len1)
                tz1 = len1 - to1
                tmp = (
                    o[:to1]
                    + zs[:tz1]
                    + o[to1:]
                    + zs[tz1:]
                )
                a[L:R] = tmp
        res = 0
        for i, ai in enumerate(a) :
            res += (ai | i)
        print(res)
        print(*a)
if __name__ == "__main__":
    solve()
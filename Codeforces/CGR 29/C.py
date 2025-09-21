import sys
input = lambda: sys.stdin.readline().rstrip()
print = lambda x: sys.stdout.write(str(x) + '\n')
def solve_case(s: str) -> bool:
    n = len(s)
    z = [i for i, ch in enumerate(s) if ch == '0']
    if not z:
        return True
    canL = [False] * n
    canR = [False] * n
    for i in z:
        canL[i] = (i == 0 or
                    s[i-1] == '0' or
                    (i >= 2 and s[i-1] == '1' and s[i-2] == '0'))
        canR[i] = (i == n-1 or
                    s[i+1] == '0' or
                    (i+2 < n and s[i+1] == '1' and s[i+2] == '0'))
    m = len(z)
    idx = 0
    while idx < m:
        j = idx
        while (j + 1 < m and
                z[j+1] == z[j] + 2 and
                s[z[j] + 1] == '1'):
            j += 1
        first = z[idx]
        cur = (1 if canL[first] else 0) | (2 if canR[first] else 0)
        if cur == 0:
            return False
        for t in range(idx + 1, j + 1):
            i = z[t]
            nxt = 0
            if (cur & 1) and canR[i]:
                nxt |= 2
            if (cur & 2) and canL[i]:
                nxt |= 1
            cur = nxt
            if cur == 0:
                return False
        idx = j + 1
    return True
def main():
    t = int(input())
    out = []
    for _ in range(t):
        n = int(input())
        s = input().strip()
        out.append("YES" if solve_case(s) else "NO")
    print("\n".join(out))
if __name__ == "__main__":
    main()

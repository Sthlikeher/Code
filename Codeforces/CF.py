import sys
input = lambda: sys.stdin.buffer.readline().rstrip()
#print = lambda x: sys.stdout.write(str(x) + '\n')
def sump(l, r) :
    print(f"1 {l} {r}", flush=True)
    return int(sys.stdin.readline().strip())
def suma(l, r) :
    print(f"2 {l} {r}", flush=True)
    return int(sys.stdin.readline().strip())
def solve(n : int):
    tt = suma(1, n)
    k = tt - n * (n + 1) // 2
    l, h = 1, n
    res = n
    while l <= h:
        mid = l + h >> 1
        sp = sump(1, mid)
        sa = suma(1, mid)
        diff = sa - sp
        if diff == k:
            res = mid
            h = mid - 1
        else :
            l = mid + 1
    l = res - k + 1
    print(f"! {l} {res}", flush=True)
def main():
    t = int(input())
    for _ in range(t) :
        n = int(input())
        solve(n)
if __name__ == "__main__":
    main()
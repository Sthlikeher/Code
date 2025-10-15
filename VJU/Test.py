import sys
input = lambda: sys.stdin.buffer.readline().rstrip()
print = lambda x: sys.stdout.write(str(x) + '\n')
def hn(n, s, aux, des, move) :
    if n == 1:
        move.append((s, des))
        return
    hn(n - 1, s, des, aux, move)
    move.append((s, des))
    hn(n - 1, aux, s, des, move)
def solve() :
    n = int(input())
    mn = (1 << n) - 1
    move = []
    hn(n, 1, 2, 3, move)
    print(mn)
    for a, b in move:
        print(f"{a} {b}")
if __name__ == "__main__":
    solve()
import sys
input = lambda: sys.stdin.buffer.readline().rstrip()
print = lambda x: sys.stdout.write(str(x) + '\n')
def solve():
    t = int(input())
    for _ in range(t) : 
        a, b = map(int, input().split())
        fi = (a // b) * b
        se = ((a + b - 1) // b) * b
        print(f"{fi} {se}")
if __name__ == "__main__":
    solve()
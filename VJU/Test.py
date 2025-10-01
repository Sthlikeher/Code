import sys

input = lambda: sys.stdin.readline().rstrip()
print = lambda x: sys.stdout.write(str(x) + '\n')

def main():
    t = int(input())
    for _ in range(t):
        a, b = map(int, input().split())
        first = (a // b) * b
        second = ((a + b - 1) // b) * b
        print(f"{first} {second}")

if __name__ == "__main__":
    main()
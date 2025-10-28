for _ in range(int(input())) :
    a, b = map(int, input().split())
    n, m = map(int, input().split())
    x = m * (n // (m + 1)) * a + n % (m + 1) * min(a, b)
    y = b * n 
    print(min(x, y))
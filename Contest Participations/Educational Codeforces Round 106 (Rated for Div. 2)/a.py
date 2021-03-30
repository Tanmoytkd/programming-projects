t = int(input())

for test in range(t):
    n, k1, k2 = map(int, input().split())
    w, b = map(int, input().split())

    pb = (k1 // 2) + (k2 // 2) + (k1 % 2) * (k2 % 2)
    nk1, nk2 = n - k1, n - k2
    pw = (nk1 // 2) + (nk2 // 2) + (nk1 % 2) * (nk2 % 2)

    if pb >= w and pw >= b:
        print("YES")
    else:
        print("NO")
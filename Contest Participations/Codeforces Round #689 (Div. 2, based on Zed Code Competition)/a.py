t = int(input())

for i in range(t):
    n, k = map(int, input().split(" "))

    repeat = (n + 2) // 3

    result = ("abc" * repeat)[:n]
    print(result)
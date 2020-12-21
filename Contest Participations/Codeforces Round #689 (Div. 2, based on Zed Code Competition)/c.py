t = int(input())

for test in range(t):
    n, m = map(int, input().split(" "))

    arr = [0]
    arr = arr + list(map(int, input().split(" ")))

    thres = n
    while thres >= 1 and arr[thres] == thres:
        thres -= 1

    inv = 1
    result = 0

    for i in range(m):
        r, p = map(float, input().split(" "))
        if r >= thres:
            result += inv * p
            inv *= 1 - p

    if thres == 0:
        result = 1

    print(result)

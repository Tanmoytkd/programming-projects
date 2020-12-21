t = int(input())

for test in range(t):
    rows, cols = map(int, input().split(" "))

    board = []

    empty_line = list("." * (cols + 2))
    board.append(empty_line)

    for row in range(rows):
        s = input()
        board.append(list("." + s + "."))

    board.append(empty_line)

    dp = board.copy()

    # print(dp)

    for i in range(len(dp)):
        dp[i] = [1 if dp[i][j] == '*' else 0 for j in range(len(dp[0]))]

    # print(dp)

    res = 0

    for i in range(rows, 0, -1):
        for j in range(cols, 0, -1):
            if dp[i][j] == 1:
                dp[i][j] += min(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1])
                res += dp[i][j]

    print(res)

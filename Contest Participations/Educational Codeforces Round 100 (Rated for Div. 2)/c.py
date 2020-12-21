import math

T = int(input())

for test in range(T):
    n = int(input())

    start_time = 0
    start_pos = 0
    end_time = 0
    end_pos = 0
    direction = 0

    success = 0

    queries = []

    for i in range(n):
        t, x = map(int, input().split(" "))
        queries.append((t, x))

    queries.append((math.inf, math.inf))

    qs = []

    for i in range(n):
        t, x = queries[i]
        t1 = queries[i+1][0]


        if t >= end_time:
            start_pos = end_pos
            end_pos = x
            direction = -1 if start_pos > end_pos else int(start_pos < end_pos)

            start_time = t
            end_time = t + abs(x-start_pos)

            if end_time <= t1:
                success += 1

        else:
            def has_success():
                global start_time, start_pos, end_time, end_pos, t, x, t1
                pos1 = start_pos + direction * (t - start_time)
                t2 = min(end_time, t1)
                pos2= start_pos + direction * (t2 - start_time)

                pos1, pos2 = min(pos1, pos2), max(pos1, pos2)

                if pos1 <= x <= pos2:
                    return True
                else:
                    return False

            if has_success():
                success += 1

    print(success)

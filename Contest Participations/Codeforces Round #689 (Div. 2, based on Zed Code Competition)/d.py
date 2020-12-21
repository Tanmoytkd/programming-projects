t = int(input())

for test in range(t):
    n, q = map(int, input().split(" "))

    a = list(map(int, input().split(" ")))
    a.sort()

    sums = set()

    def go(st, fn):
        # print (st, "-", fn)
        global a, sums

        if st >= fn:
            return

        s = 0
        for i in range(st, fn):
            s += a[i]

        sums.add(s)

        if (fn - st) > 1:
            mid = (a[st] + a[fn-1]) // 2

            i = st
            while i < fn and a[i] <= mid:
                i += 1

            if i != fn:
                go(st, i)
                go(i, fn)

    go(0, len(a))

    # print(sums)

    for _ in range(q):
        query = int(input())

        if query in sums:
            print("Yes")
        else:
            print("No")

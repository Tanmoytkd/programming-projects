t = int(input())

for test in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    if len(arr) == 1:
        print(0)
    else:
        diff = [arr[i] - arr[i-1] for i in range(1, n)]

        diffset = sorted(list(set(diff)))

        if len(diffset) > 2:
            print(-1)
        elif len(diffset) == 1:
            print(0)
        else:
            if all((d > 0 for d in diffset)) or all((d < 0 for d in diffset)) or 0 in diffset:
                print(-1)
            else:
                s = arr[0]
                c = diffset[-1]
                m = sum(map(abs,diffset))

                if s >= m or c >= m:
                    print(-1)
                else:
                    print(m, c)
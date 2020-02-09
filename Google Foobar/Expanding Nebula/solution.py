from itertools import izip


def generateColumn(rows, row=0):
    if row == rows - 1:
        yield [[0]]
        yield [[1]]
    else:
        for col in generateColumn(rows, row + 1):
            yield col + [[0]]
            yield col + [[1]]


def match(col1, col2, tcol):
    col = [c1 + c2 for c1, c2 in izip(col1, col2)]
    for i in range(len(col) - 1):
        tval = 1 if tcol[i][0] is True else 0
        nc = [col[i][0]] + [col[i][1]] + [col[i + 1][0]] + [col[i + 1][1]]
        trueCount = nc.count(True)
        rval = 1 if trueCount == 1 else 0

        if tval != rval:
            return False
    return True


dp = dict()


def getCol(g, cpos):
    return [[g[i][cpos]] for i in range(len(g))]


def rec(g, cpos, cprev):
    rows = len(g)
    tcol = getCol(g, cpos)

    if cpos < 0:
        return 1
    else:
        cprev_str = ''
        for val in cprev:
            cprev_str = cprev_str + str(val)
        if (cpos, cprev_str) not in dp:
            ret = 0
            for col in generateColumn(rows + 1):
                if match(col, cprev, tcol):
                    ret += rec(g, cpos - 1, col)
            dp[(cpos, cprev_str)] = ret
        return dp[(cpos, cprev_str)]


def solution(g):
    rows = len(g)
    cols = len(g[0])

    ret = 0
    for col in generateColumn(rows + 1):
        ret += rec(g, cols - 1, col)
    return ret


c1 = [[False],
      [False],
      [True],
      [False]]

c2 = [[False],
      [False],
      [False],
      [True]]

c3 = [[False],
      [True],
      [False]]

# print match(c1, c2, c3)

g = [[True, True, False, True, False, True, False, True, True, False], [True, True, False, False, False, False, True, True, True, False], [True, True, False, False, False, False, False, False, False, True], [False, True, False, False, False, False, True, True, False, False]]
print solution(g)

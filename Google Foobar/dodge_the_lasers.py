import math

sqrt2 = 4142135623730950488016887242096980785696718753769480731766797379907324784621070388503875343276415727

def calc_n1(n):
    return (sqrt2*n)//10**100

def calc(n):
    if n==1:
        return 1
    if n<1:
        return 0
    t = calc_n1(n)
    res = n*t + n*(n+1)/2 - t*(t+1)/2 - calc(t)
    return res

def answer(str_n):
    num = int(str_n)
    res = calc(num)
    return str(res)
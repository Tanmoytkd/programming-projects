#include <stdio.h>
#include<limits.h>
#define gc getchar_unlocked
#define pc putchar_unlocked

typedef long long lint;

void writelint (lint n)
{
    lint N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} /*obtain the count of the number of 0s*/
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  /*store reverse of N in rev*/
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

int scanlint(lint * num)
{
    register int c = gc();
    lint x = 0;
    for(;(c<48 || c>57);c = gc()) {
        if(c==EOF) return 0;
    }
    for(;c>47 && c<58;c = gc()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    *num = x;

    return 1;
}

int main()
{
    long long a, b, v, res1;
    while(scanlint(&a) && scanlint(&b)) {
        res1= (a>b) ? a-b : b-a;
        writelint(res1);
        pc('\n');
    }
    return 0;
}

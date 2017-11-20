#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;

char convert(char ch) {
    if(ch=='1'|| ch=='0'||ch=='-') return ch;
    if(ch>='A' && ch<='C') return '2';
    if(ch>='D' && ch<='F') return '3';
    if(ch>='G' && ch<='I') return '4';
    if(ch>='J' && ch<='L') return '5';
    if(ch>='M' && ch<='O') return '6';
    if(ch>='P' && ch<='S') return '7';
    if(ch>='T' && ch<='V') return '8';
    if(ch>='W' && ch<='Z') return '9';
}

int main() {
    char str[1000];
    while(gets(str)!=NULL) {
        int len=strlen(str);
        for(int i=0; i<len; i++) {
            str[i]=convert(str[i]);
        }
        puts(str);
    }
    return 0;
}

/*
ID: tanmoyk2
PROG: crypt1
LANG: C++11
*/
#include<bits/stdc++.h>
using namespace std;


int mark[10];

int valid(int num) {
    do {
        int dig = num%10;
        if(!mark[dig]) return 0;
        num/=10;
    } while(num!=0); 
    return 1;
}

int main()
{
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int n;
    fin >> n;

    int dig;
    for(int i=0; i<n; i++) {
        fin >> dig;
        mark[dig]=1;
    }

    int res=0;
    for(int big=100; big<=999; big++) {
        if(!valid(big)) continue;
        for(int small = 10; small<=99; small++) {
            if(!valid(small)) continue;
            
            int f1=big*(small%10), f2=big*(small/10), mul = big*small;
            if(f1<100 || f1>999 || !valid(f1)) continue;
            if(f2<100 || f2>999 || !valid(f2)) continue;
            if(mul<1000 || mul>9999 || !valid(mul)) continue;
            res++;
        }
    }

    fout << res << endl;

    return 0;
}

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
int compo[1050];

void sieve() {
    for(int i=4; i<1050; i+=2) compo[i]=1;
    for(int i=3; i<100; i+=2) {
        if(!compo[i]) {
            for(int j=i+i; j<1050; j+=i) compo[j]=1;
        }
    }
}

int main() {
    sieve();
    char str[21];
    while(sf("%s", str)==1) {
        int sum=0, len=strlen(str);
        for(int i=0; i<len; i++) {
            if(isupper(str[i])) sum+= str[i]-'A'+27;
            else sum+=str[i]-'a'+1;
        }

        if(!compo[sum]) pf("It is a prime word.\n");
        else pf("It is not a prime word.\n");
    }

    return 0;
}

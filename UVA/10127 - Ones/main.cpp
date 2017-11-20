#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n)==1) {
        int count=1, dividant=1;
        for(dividant=1; dividant%n!=0; count++) {
            dividant=((((dividant%n)*(10%n))%n)+(1%n))%n;
        }
        printf("%d\n", count);
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int house=2, sum=-1, last=house, i=0;

    while(i<10) {
        sum+= house-1+house;
        int tempsum=sum;

        while(tempsum>=last) {
            last++;
            tempsum-=last;
        }

        if(tempsum==1) {
            printf("%10d%10d\n", house, last);
            i++;
        }
        house++;
        sum=tempsum;
    }

    return 0;
}

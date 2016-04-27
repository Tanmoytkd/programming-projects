#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int house=1, sum=0, last, i=0;

    while(i<10) {
        sum+= house-1;
        int tempsum=sum;

        last=house+1;
        tempsum-=last;
        while(tempsum>0) {
            last++;
            tempsum-=last;
        }

        if(tempsum==0) {
            printf("%10d %10d\n", house, last);
            i++;
            house*=2;
            sum=(house-1)*(house-2)/2;
        }
        else {
            printf("%10d %10d %10d\n", house, last, tempsum);
            getch();
            house++;
        }

    }

    return 0;
}

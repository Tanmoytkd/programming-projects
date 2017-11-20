#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    long long h, l;

    while(1) {
        scanf("%lld %lld", &l, &h);
        if(h==0 || l==0) break;
        else if(h<l) {
            long long temp=h;
            h=l;
            l=temp;
        }

        long long max=0, counter=0, res, i=l, m, pos, nums=h-l+1;
        char check[nums];
        for(m=0; m<nums; m++) check[m]=0;

        for(i=l; i<=h; i++) {
            counter=0;
            if(check[i-l]==1) continue;
            long long temp=i;
            while(1) {
                if(temp&1) {
                    temp=3*temp+1;
                }
                else {
                    temp>>=1;
                }
                pos=(temp-l);
                if(pos>=0 && pos<nums) check[pos]=1;
                counter++;

                if(temp==1) break;
            }
            if(counter>max) {
                max=counter;
                res=i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", l, h, res, max);
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int test;
    cin >> test;

    for(int i=1; i<=test; i++) {
        int nums, n;
        cin >> nums;
        int unsorted[nums], sorted[nums];
        for(int j=0; j<nums; j++) {
            cin >> n;
            unsorted[j]=n;
            sorted[j]=n;
        }
        sort(sorted, sorted+nums);
        int p1=0, p2=0, movecount=0;
        while(p1<nums) {
            if(unsorted[p1]!=sorted[p2]) {
                movecount++;
            }
            else {
                p2++;
            }
            p1++;
        }
        printf("Case %d: %d\n", i, movecount);
    }
    return 0;
}

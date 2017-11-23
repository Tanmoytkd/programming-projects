#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test=0;
    while(scanf("%d", &test)!=EOF) {
        int nums[test];
        int i;
        for(i=0; i<test; i++) {
            scanf("%d", &nums[i]);
        }
        int flips=0;
        int check=0;
        while(check==0) {
            int pos=0;
            while(nums[pos]<=nums[pos+1]) {
                pos++;
                if(pos==(test-1)) {
                    check=1;
                    break;
                }
            }
            if(nums[pos]>nums[pos+1]) {
                int temp = nums[pos];
                nums[pos]=nums[pos+1];
                nums[pos+1]=temp;
                flips++;
            }
        }
        printf("Minimum exchange operations : %d\n", flips);
    }
    return 0;
}

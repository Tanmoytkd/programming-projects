#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cases;
    scanf("%d", &cases);
    int i;
    for(i=1; i<=cases; i++) {
        int s1=0, s2=0, s3=0;
        scanf("%d %d %d", &s1, &s2, &s3);
        printf("Case %d: ", i);
        if((s1<s2 && s1>s3) || (s1>s2 && s1<s3) || (s1==s2)) {
            printf("%d\n", s1);
        }
        else if((s2<s1 && s2>s3) || (s2>s1 && s2<s3)) {
            printf("%d\n", s2);
        }
        else {
            printf("%d\n", s3);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0, y=0;
    scanf("%d", &x);
    scanf("%d", &y);
    printf("Old x= %d, Old y=%d\n", x, y);
    x=x+y;
    printf("x= %d, y=%d\n", x, y);
    y=x-y;
    printf("x= %d, y=%d\n", x, y);
    x=x-y;
    printf("New x= %d, New y=%d\n", x, y);
    return 0;
}

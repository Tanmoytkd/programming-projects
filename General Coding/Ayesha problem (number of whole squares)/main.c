#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, b=100000;

    int num=0;
    for(i=1; i*i<=b; i++) num++;
    printf("%d\n", num);


    /*num=0;
    for(i=1; i<b; i++) {
        if(i*i>=a && i*i<=b) num++;
    }

    printf("%d\n", num);*/



    return 0;
}

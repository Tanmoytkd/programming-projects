#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=0, counter=0, digit=0, divider=1;
    printf("Please enter a number: ");
    scanf("%d", &num);

    while(divider*10 <= num) {
        divider *= 10;
    }
    printf("\n");

    while(divider) {
        digit = num/divider;
        printf("%d, ", digit);
        num = num%divider;
        divider = divider/10;
        counter++;
    }
    printf("\n\nNumber of digits: %d\n\n", counter);
    return 0;
}

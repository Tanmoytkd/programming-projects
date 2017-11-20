#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long arr[1500], arr2[1000], arr3[1000], arr5[1000];
    arr[0]=1;
    arr2[0]=2;
    arr3[0]=3;
    arr5[0]=5;

    long long i22=0, i32=0, i52=0, i23=0, i33=0, i53=0, i25=0, i35=0, i55=0, p2=1, p3=1, p5=1;

    while(p2<1000 && p3<1000 && p5<1000) {
        /*for array2*/
        long long shortest=arr2[i22]*2, p=22;
        if(arr3[i32]*2<shortest) {
            shortest=arr3[i32]*2;
            p=32;
        }
        else if(arr5[i52]*2<shortest) {
            shortest=arr5[i52]*2;
            p=52;
        }

        switch(p) {
            case 22: i22++; break;
            case 32: i32++; break;
            case 52: i52++; break;
        }
        arr2[p2]=shortest;
        p2++;

        /*for array3*/
        shortest=arr2[i23]*3, p=23;
        if(arr3[i33]*3<shortest) {
            shortest=arr3[i33]*3;
            p=33;
        }
        else if(arr5[i53]*3<shortest) {
            shortest=arr5[i53]*3;
            p=53;
        }

        switch(p) {
            case 23: i23++; break;
            case 33: i33++; break;
            case 53: i53++; break;
        }
        arr3[p3]=shortest;
        p3++;

        /*for array5*/
        shortest=arr2[i25]*5, p=25;
        if(arr3[i35]*5<shortest) {
            shortest=arr3[i35]*5;
            p=35;
        }
        else if(arr5[i55]*5<shortest) {
            shortest=arr5[i55]*5;
            p=55;
        }

        switch(p) {
            case 25: i25++; break;
            case 35: i35++; break;
            case 55: i55++; break;
        }
        arr5[p5]=shortest;
        p5++;

    }

    int i;
    for(i=0; i<1000; i++) {
        printf("%lld\t%lld\t%lld\n", arr2[i], arr3[i], arr5[i]);
    }

    return 0;
}

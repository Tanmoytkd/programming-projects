#include <iostream>
#include<bits/stdc++.h>
#include <conio.h>

using namespace std;

int isSquare(long long num) {
    long long h= num & 0xF; //last hexadecimal digit
    if (h > 9)
        return 0; // return immediately in 6 cases out of 16.

    // Take advantage of Boolean short-circuit evaluation
    if ( h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8 )
    {
        // take square root if you must
        int t = (int) floor( sqrt((double) num) + 0.5 );
            if(t*t == num) return t;
    }
    return -1;
}

int main()
{
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    long long x=1, counter=0, res;

    /*while(cin >> num) {
        if(num<0) break;
        if(isSquare(num)) cout << num << "  is a square number" << endl;
        else cout << num << "  is not a square number" << endl;
    }*/

    for(x=2; counter<10; x++) {
        //long long determine= (2*x+1)*(2*x+1) + 4*x*(x-1);
        long long determine= 8*x*x+1;
        //cout << determine << endl;
        //getch();
        res=isSquare(determine);
        if(res !=-1) {
            res=(res-1)/2;
            //cout << x << " " << res << endl;
            counter++;
            printf("%10lld %10lld\n", x, res);
        }
    }

    return 0;
}

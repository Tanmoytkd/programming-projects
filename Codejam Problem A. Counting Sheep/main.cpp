#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef TKD
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int testcase;
    cin >> testcase;

    for(int i=1; i<=testcase; i++) {
        bool check[10];
        for(int j=0; j<10; j++) check[j]=false;

        int number;
        cin >> number;

        cout << "Case #" << i << ": ";

        if(number == 0) cout << "INSOMNIA" << endl;
        else {
            int counter=0, n=1, num;
            while(counter != 10) {
                num=number*n;
                while(num) {
                    int dig=num%10;
                    num/=10;
                    if(check[dig]==false) {
                        counter++;
                        check[dig]=true;
                    }
                }
                if(counter==10) cout << number*n << endl;
                n++;
            }
        }
    }

    return 0;
}

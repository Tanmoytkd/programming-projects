#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    int testcase;
    scanf("%d", &testcase);

    for(int k=1; k<=testcase; k++) {
        double u=0, i=0, p=0, cp=0, cu=0, ci=0, num;
        char ch;

        for(int j=0; j<2; j++) {
                scanf("%*[^=]%*c%lf", &num);
                //cout << num << endl;
                cin >> ch;
                //cout << " " << ch << " ";
                if(ch=='m' || ch=='k' || ch=='M') {
                    switch(ch) {
                    case 'm': num/=1000; break;
                    case 'k': num*=1000; break;
                    case 'M': num*=1000000; break;
                    }
                    cin >> ch;
                    //cout << ch << " ";
                }
                switch(ch) {
                case 'V': u=num; cu=1; break;
                case 'A': i=num; ci=1; break;
                case 'W': p=num; cp=1; break;
                }
                //cout << endl;
        }

        //cout << u << " " << i  << " " << p << endl;

        if(cu==0) {
            u=p/i;
            printf("Problem #%d\nU=%.2lfV\n\n", k,u);
            //cout << u << " " << i  << " " << p << endl;
        }
        else if(ci==0) {
            i=p/u;
            printf("Problem #%d\nI=%.2lfA\n\n", k, i);
            //cout << u << " " << i  << " " << p << endl;

        }
        else if(cp==0) {
            p=u*i;
            //cout << u << " " << i  << " " << p << endl;
            printf("Problem #%d\nP=%.2lfW\n\n", k, p);
        }
    }

    return 0;
}

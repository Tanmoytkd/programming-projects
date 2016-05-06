#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void calculate(int num[], int i, int res, bool &possible) {

    if(i==5) {
        if(res==23)
            possible=true;

        return;
    }

    res+=num[i];
    calculate(num, i+1, res, possible);
    res-=num[i];
    if(possible) return;

    res-=num[i];
    calculate(num, i+1, res, possible);
    res+=num[i];
    if(possible) return;

    res*=num[i];
    calculate(num, i+1, res, possible);
    res/=num[i];
}

int main()
{
    int num[5];

    while(1) {
        cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
        if(num[0]==0 && num[1]==0 && num[2]==0 && num[3]==0 && num[4]==0) break;

        sort(num, num+5);

        bool possible=false;
        do {
            int res=num[0];
            calculate(num, 1, res, possible);
        } while(next_permutation(num, num+5) && !possible);


        if(possible==true) cout << "Possible" << endl;
        else cout << "Impossible" << endl;

    }

    return 0;
}

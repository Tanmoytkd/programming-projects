#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int n, songs, maxsum;
vector<int>maximum;
vector<int>current;

void calculate(int track[], int used[], int sum) {
    if(sum<=n && sum>maxsum) {
        maximum=current;
        maxsum=sum;
    }

    if(sum>n) {
        //sum-=current.back();
        //current.pop_back();
        return;
    }

    for(int i=0; i<songs; i++) {
        if(used[i]==0) {
            used[i]=1;
            current.push_back(track[i]);
            sum+=track[i];

            if(sum>n) {
                sum-=current.back();
                current.pop_back();
                continue;
            }

            calculate(track, used, sum);

            sum-=current.back();
            for(int j=i+1; j<songs; j++) {
                used[j]=0;
            }
            current.pop_back();
        }
    }
}

int main()
{
    #ifdef TKD
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif


    while(cin >> n >> songs) {
        int track[songs], used[songs];
        for(int i=0; i<songs; i++) {
            cin >> track[i];
            used[i]=0;
        }

        int sum=0, len;
        calculate(track, used, sum);

        len=maximum.size();
        for(int i=0; i<len; i++) {
            cout << maximum[i] << " ";
        }
        cout << "sum:" << maxsum << endl;

        maximum.clear();
        current.clear();
        maxsum=0;
    }

    return 0;
}

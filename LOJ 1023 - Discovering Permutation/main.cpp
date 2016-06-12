#include <bits/stdc++.h>

using namespace std;

bool flag[26];
string str="";
void permute(int N, int K, int &counter) {
    if(counter==K) return;
    int len=str.length();
    if(len==N) {
        counter++;
        cout << str << endl;
        return;
    }

    for(int i=0; i<N; i++) {
        if(flag[i]==false) {
            flag[i]=true;
            str+='A'+i;
            permute(N, K, counter);
            flag[i]=false;
            str=str.substr(0, str.length()-1);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    for(int i=1; i<=T; i++) {
        for(int j=0; j<26; j++) flag[j]=false;
        int N, K, counter=0;
        cin >> N >> K;
        cout << "Case " << i << ":" << endl;
        permute(N, K, counter);
    }
    return 0;
}

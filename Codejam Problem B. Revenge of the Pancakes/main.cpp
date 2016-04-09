#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef TKD
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int testcase;
    char ch, str[105];
    cin >> testcase;
    ch=getchar();

    for(int i=1; i<=testcase; i++) {
        gets(str);
        int len=strlen(str);

        char str2[105];              //remove repetition
        str2[0]=str[0];
        int pos=1;
        for(int j=1; j<=len; j++) {
            if(str[j]!=str[j-1]) {
                str2[pos]=str[j];
                pos++;
            }
        }

        int len2=strlen(str2);  //remove last +;
        if(str2[len2-1]=='+') {
            str2[len2-1]='\0';
            len2--;
        }

        cout << "Case #" << i << ": " << len2 << endl;
    }

    return 0;
}

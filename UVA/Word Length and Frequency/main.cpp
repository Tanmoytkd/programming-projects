#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    char str[1000];
    bool start=true;

    while(scanf("%[^#]", str)==1) {
        if(start) start=false;
        else cout << endl;

        int i, j, len;
        map<int, int> occur;
        for(i=0, j=0; str[j]!='\0'; i++, j++) {
            if(str[j]=='-' && str[j+1]=='\n') j+=2;
            if(str[j]=='-' && str[j+1]!='\n') j+=1;
            if(str[j]=='\'') j+=1;
            if(str[j]=='\"') j+=1;
            str[i]=str[j];
        }
        str[i]=str[j];

        len=strlen(str);
        for(i=0; i<len; i++) {
            if(isalpha(str[i])==0) str[i]=' ';
        }
        string str1=str;

        stringstream ss(str1);
        while(ss>>str1) {
            int l=str1.length();
            if(occur.find(l)==occur.end()) occur[l]=1;
            else occur[l]++;
        }

        typedef map<int, int>::iterator it_type;

        for(it_type it=occur.begin(); it!=occur.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
        fgets(str, 999, stdin);
    }

    return 0;
}

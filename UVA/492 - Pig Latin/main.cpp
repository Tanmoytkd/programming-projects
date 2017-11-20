#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int isvowel(char ch) {
    ch=tolower(ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

int main()
{
#ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    char ch, startchar, prev='\0';
    int start=1, flag=0;

    while(scanf("%c", &ch)==1)
    {
        if(isalpha(ch))
        {
            if(start)
            {
                start=0;
                startchar=ch;
		prev=ch;
                if(isvowel(ch)==0) {
                    flag=1;
                    continue;
                }
            }
        }
        else
        {
            start=1;
            if(flag) {
                flag=0;
                cout << startchar;
            }
            if(isalpha(prev)) cout << "ay";

            start=1;
        }

        cout << ch;
        prev=ch;
    }

    if(flag) cout << startchar << "ay";

    return 0;
}

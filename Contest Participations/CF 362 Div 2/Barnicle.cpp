#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back

using namespace std;

int main() {
    char num[120];
    int b;
    scanf("%s", num);


    int len=strlen(num);
    int epos=find(num, num+len, 'e')-num;
    num[epos]=0;
    b=atoi(num+(epos+1));

//    pf("%s\n", num);
//    cout << b << endl;

    len=strlen(num);

    int pos=(find(num, num+len, '.')-num);
    if(pos!=len) {
        while(b && pos!=len-1) {
            swap(num[pos], num[pos+1]);
            pos++;
            b--;
        }
        if(pos==len-1) num[pos]=0;
    }

    len=strlen(num);
    if(num[len-1]=='0' && num[len-2]=='.') num[len-2]=0;

    char *res=num;
    while(*res=='0'&& *(res+1)!='.') res=res+1;
    pf("%s", res);
//    system("PAUSE");
    for(int i=0; i<b; i++) pf("0");
    pf("\n");

    return 0;
}

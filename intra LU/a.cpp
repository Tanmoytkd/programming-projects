#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch[1000];
    gets(ch);
    int len = strlen(ch);
    for(int i=0; i<len; i++) {
        if(ch[i]!=' ') printf("%c", ch[i]);
    }
    return 0;
}

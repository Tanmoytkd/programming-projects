#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    stack<int> st;
//    int mark[n+1];
//    memset(mark, 0, sizeof mark);
    int pos=1, res=0;
    char s[100];
    for(int i=1; i<=(n*2); i++) {
        scanf("%s", s);
        if(s[0]=='a') {
            int num;
            scanf("%d", &num);
            st.push(num);
//            mark[num]=1;
        }
        else {
            if(!st.empty() && st.top()==pos) {
                st.pop();
            }
            else if(!st.empty() && st.top()!=pos) {
                st=stack<int>();
                res++;
            }
            pos++;
        }
    }

    printf("%d", res);
    return 0;
}

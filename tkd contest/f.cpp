#include <bits/stdc++.h>
using namespace std;
#define MAX_NODE 1000007
#define MAX_LEN 1007

int n, m;
char str[10007], s[1007];
int root, nnode;
int node[MAX_NODE][26], isword[MAX_NODE];
vector<string> v;
map<string, string> mp;

void initialize() {
    root=0;
    nnode=0;
    for(int i=0; i<26; i++) {
        node[root][i]=-1;
    }
}

void iinsert() {
    scanf("%s", s);

    int len=strlen(s);
    char S[len+1];
    for(int i=0; i<len; i++) S[i]=tolower(s[i]);
    S[len]=0;
    reverse(S, S+len);
    mp[S]=s;

    int now=root;
    for(int i=0; i<len; i++) {
        int chpos=S[i]-'a';
        //cout << S[i] << " " << chpos << endl;
        if(node[now][chpos]==-1) {
            node[now][chpos]=++nnode;
            for(int j=0; j<26; j++) {
                node[nnode][j]=-1;
            }
        }
        now=node[now][chpos];
    }
    isword[now]=1;
}

int found=0;

void go(int pos) {
    //cout << pos << endl;

    if(pos==n) {
        for(int i=0; i<v.size(); i++) {
            cout << mp[v[i]] << " \n"[i==v.size()-1];
        }
        found=1;
        return;
    }
    int now=root;
    string x="";
    int chpos=str[pos]-'a';
    //cout << root << " " << chpos << " " << node[now][chpos] << endl;
    while(node[now][chpos]!=-1) {
        x+=str[pos];
        //cout << x << endl;
        now=node[now][chpos];
        if(isword[now]) {
            v.push_back(x);
            go(pos+1);
            if(found) return;
            v.pop_back();
        }
        pos++;
        chpos=str[pos]-'a';
    }

}

int main() {
    scanf("%d", &n);
    scanf("%s", str);
    scanf("%d", &m);
    initialize();
    while(m--) {
        iinsert();
    }





    go(0);
}

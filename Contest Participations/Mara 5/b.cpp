/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define FOR(I, N) for(int I=0; I<N; I++)
#define FOR1(I, N) for(int I=1; I<=N; I++)

using namespace std;

#define mod 1000000007

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}

int parent[256];
string p[256];



int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int first=1;
    int t;
    sf1(t);
    while(t--) {
        memset(parent, 0, sizeof parent);
        for(int i='A'; i<='Z'; i++) p[i]="";

        if(first) first=0;
        else puts("");

        int r, q;
        sf2(r, q);

        char par[50], chi[50], src[50], dest[50];
        while(r--) {
            sf("%s %s", par, chi);
            //cout << chi[0] << " " << par[0] << endl;
            parent[chi[0]] = par[0];
        }

        for(int i='A'; i<='Z'; i++) {
            if(parent[i]==0) continue;
            int s=i;
            while(i!=0) {
                p[s]+=i;
                i=parent[i];
            }
            i=s;
        }

//        for(int i='A'; i<='Z'; i++) {
//            cout << (char) i << " " << (char) parent[i] << endl;
//        }

        while(q--) {
            sf("%s %s", src, dest);
            int x=src[0], y=dest[0];

            string s1=p[x], s2=p[y];
//            cout << s1 << endl << s2 << endl;
            int l1=s1.length()-1, l2=s2.length()-1;
            char root=0;;
            while(l1>=0 && l2>=0 && s1[l1]==s2[l2]) {
                root=s1[l1];
                s1.erase(l1);
                s2.erase(l2);
                l1--;
                l2--;
            }
            if(root!=0)s1+= root;
            for(int i=s2.length()-1; i>=0; i--) {
                s1+=s2[i];
            }
            cout << s1 << endl;
        }
    }

    return 0;
}

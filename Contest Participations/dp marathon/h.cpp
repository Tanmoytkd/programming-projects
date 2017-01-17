#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

vector<int> pos[256];
string s;
lint dp[70][70];
int level=0;

lint rec(int start, int fin) {
    //cout << level << " " << start << " " << fin << endl;
    if(start>=fin) {
        //cout << level << " " << start << " " << fin << " 0" << endl;
        level--;
        return 0;
    }
    if(fin-start==1) {
        //cout << level << " " << start << " " << fin << " 1" << endl;
        level--;
        return 1;
    }

    if(dp[start][fin]==-1) {
        lint & res=dp[start][fin];
        res=0;

        for(int i=start; i<fin; i++) {
            ////cout << start << " " << fin << endl;
            char ch=s[i];
            vector<int> & v=pos[ch];
            vector<int>::iterator it=lower_bound(v.begin(), v.end(), fin);
            int chpos=it-v.begin();
            chpos--;
            //if(chpos<0) continue;
            while(chpos>=0 && v[chpos]>=i) {
                ////cout << level << " " << start << " CHPOS= " << chpos << " " << v[chpos]+1 << " 1+" <<endl;
                level++;
                res+=1+rec(i+1, v[chpos]);
                chpos--;
            }

//            for(int position=v.size()-1; position>=0; position--) {
//                if(v[position]<start) break;
//            }
        }
    }
    return dp[start][fin];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    vector<int> blank;
    while(t--) {
        for(int ipos='A'; ipos<='Z'; ipos++) pos[ipos]=blank;
        mem(dp, -1);
        cin >> s;

        FOR(i, s.length()) {
            char ch=s[i];
            pos[ch].pb(i);
        }

        lint res= rec(0, s.length());

        pf("Case %d: %lld\n", tst++, res);
    }
    return 0;
}

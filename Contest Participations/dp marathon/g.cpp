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
string s;
int dp[55][3][10];

int isvowel(char ch) {
    switch(ch) {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U': return 1;
    }
    return 0;
}

int rec(int pos, int vowel, int occur) {
    if(vowel==1 && occur==3) return 0;
    if(vowel==0 && occur==5) return 0;
    if(pos==s.length()) return 1;

    if(dp[pos][vowel][occur]==-1) {
        int & ret = dp[pos][vowel][occur];
        ret=0;

        char ch=s[pos];
        if(isvowel(ch)) {
            if(vowel) ret=rec(pos+1, vowel, occur+1);
            else ret=rec(pos+1, !vowel, 1);
        }
        else if(ch!='?') {
            if(!vowel) ret=rec(pos+1, vowel, occur+1);
            else ret=rec(pos+1, !vowel, 1);
        }
        else {
            int res1=rec(pos+1, vowel, occur+1);
            int res2=rec(pos+1, !vowel, 1);
            if(res1>res2) swap(res1, res2);
            if(res1==3 || res2==3) ret=3;
            else if(res1==0 && res2==1) ret=3;
            else if(res1==0 && res2==0) ret=0;
            else if(res1==1 && res2==1) ret=1;
        }
    }
    return dp[pos][vowel][occur];
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--) {
        mem(dp, -1);
        cin >> s;
        int res=rec(0, 0, 0);
        pcase(tst++);
        if(res==0) puts("BAD");
        else if(res==1) puts("GOOD");
        else if(res==3) puts("MIXED");
    }
    return 0;
}

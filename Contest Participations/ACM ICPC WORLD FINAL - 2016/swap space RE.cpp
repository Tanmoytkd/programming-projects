#include<bits/stdc++.h>
#define pii pair<long long,long long>
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
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
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

bool comp(pii a, pii b) {
    lint c1=a.fs;
    lint bf=b.fs-min(b.fs, a.sc);
    c1+=bf;
    lint c2=b.fs;
    lint af=a.fs-min(a.fs, b.sc);
    c2+=af;

    if(c1<c2) return true;
    if(c1>c2) return false;
    if(a.fs<b.fs) return true;
    if(a.fs>b.fs) return false;
    if(a.sc>b.sc) return true;
    if(a.sc<b.sc) return false;
    return true;
}

void imerge(vector<pii>& a,int p,int q,int r)
{
//    cout<<"Entered merge"<<endl;
    int n1=q-p+1;
    int n2=r-q;
    pii L[n1+1];
    pii R[n2+1];
    for(int i=1;i<=n1;i++)
    {
        L[i]=a[p+i-1];
    }
    for(int j=1;j<=n2;j++)
    {
        R[j]=a[q+j];
    }
    L[n1+1]=pii(INT_MAX, 0);
    R[n2+1]=pii(INT_MAX, 0);
    int i=1, j=1;
    for(int k=p;k<=r;k++)
    {
        if(comp(L[i],R[j]))
        {
            a[k]=L[i];
            i=i+1;
        }
        else
        {
            a[k]=R[j];
            j=j+1;
        }
    }
}

void merge_sort(vector<pii>& a,int p,int r)
{
    int q;
    if(p<r)
    {
     q=(p+r)/2;
     merge_sort(a,p,q);
     merge_sort(a,q+1,r);
     imerge(a,p,q,r);
    }
}

int main()
{
    int t, tst = 1;
    int n;
    sf1(n);
    lint res=0;
    lint left=0;
    vector<pii> v;


    lint a, b;
    FOR(i, n) {
        sf2ll(a,b);
        v.pb(pii(a,b));
    }

    sort(v.begin(), v.end(), comp);
//    merge_sort(v, 0, v.size()-1);

    FOR(i, v.size()) {
        lint fsize=v[i].fs;
        lint lsize=v[i].sc;

        lint mini=min(fsize, left);

        fsize-=mini;
        left-=mini;
        res+=fsize;
        left+=lsize;
    }

	//pf("%lld\n", res);
    pf("%I64d\n", res);
    //cout << res << endl;
    return 0;
}

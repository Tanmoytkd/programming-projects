/*
ID: tanmoyk2
PROG: holstein
LANG: C++11
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi() printf("hi!\n")
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





bool comp(int a, int b) {
	if(__builtin_popcount(a)==__builtin_popcount(b)) {
		return a<b;
	}
	else return __builtin_popcount(a)<__builtin_popcount(b);
}

int n=15, v, f;
int data[30][30];
std::vector<int> food(31);


int check(int flag) {
	
	std::vector<int> total(31);

	for(int i=0; i<f; i++) {
		if(flag&(1<<i)) {
			for(int j=0; j<v; j++) {
				total[j]+=data[i][j];
			}
		}
	}


	for(int i=0; i<v; i++) if(total[i]<food[i]) return 0;
	return 1;
}

int main()
{
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
    
    fin >> v;
    for(int j=0; j<v; j++) fin >> food[j];

    fin >> f;

    for(int k=0; k<f; k++) {
    	for(int l=0; l<v; l++) {
    		fin >> data[k][l];
    	}
    }

	vector<int> arr;
    int totalsize = (1<<f) -1;
    for(int i=0; i<=totalsize; i++) {
    	arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), comp);


    int possible = 0;

	for(int i=0; i<arr.size(); i++) {
		if(possible) break;
		possible = check(arr[i]);
		if(!possible) continue;
		fout << __builtin_popcount(arr[i]);
		for(int x=0; x<f; x++) {
			if(arr[i]&(1<<x)) fout << " " << x+1;
		}
		fout << endl;
	}
    
    return 0;
}

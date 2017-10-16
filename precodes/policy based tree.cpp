#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define val first
#define index second
#define pii pair<long long, long long>

typedef
tree<
  long long,
  null_type,
  less<long long>,
  rb_tree_tag,
  tree_order_statistics_node_update>
bst;

bool comp(pii a, pii b) {
	if(a.val==b.val) return a.index<b.index;
	return a.val>b.val; 
}

int main() {
	long long t, tst=1;
	scanf("%lld", &t);
	while(t--) {
		long long n, m;
		scanf("%lld%lld", &n, &m);
		std::vector<pii > v;
		v.push_back(pii(0, 0));
		for(long long i=1; i<=n; i++) {
			long long people;
			scanf("%lld", &people);
			v.push_back(pii(people, i));
		}

		sort(v.begin()+1, v.end(), comp);

		long long count[n+1];
		count[0]=0;
		for(long long i=1; i<n; i++) {
			count[i]=v[i].val-v[i+1].val;
		}
		count[n]=v[n].val;

		long long cumcount[n+1];
		cumcount[0]=0;
		for(long long i=1; i<=n; i++) {
			cumcount[i]= i*count[i]+cumcount[i-1];
		}

		printf("Case %lld:", tst++);

		std::vector<pii > queries;
		for(long long i=1; i<=m; i++) {
			long long k;
			scanf("%lld", &k);
			queries.push_back(pii(k, i));
		}
		sort(queries.begin(), queries.end());
		long long res[m+1];
		long long pos=1;


		bst X;

		for(long long i=0; i<m; i++) {
			long long k = queries[i].val;
			long long kindex = queries[i].index;

			long long repeat = lower_bound(cumcount, cumcount+n+1, k)-cumcount;
			long long left = k-cumcount[repeat-1];

			while(pos<=repeat) {
				X.insert(v[pos].index);
				pos++;
			}

			long long finalindex = *X.find_by_order((left-1)%repeat);
			res[kindex]=finalindex;
		}

		for(long long i=1; i<=m;i++) {
			printf(" %lld", res[i]);
		}
		puts("");
	}
	return 0;
}
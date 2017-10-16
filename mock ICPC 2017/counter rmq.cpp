#include <bits/stdc++.h>
using namespace std;
int l[20007], r[20007], rmq[20007];

int comp(int a, int b) {
	return rmq[a]<rmq[b];
}

int main() {
	int t, tst=1;
	scanf("%d" ,&t);
	while(t--) {
		int n, q;
		scanf("%d %d", &n, &q);
		int arr[n+1];
		for(int i=1; i<=n; i++) {
			arr[i]=1;
		}
		for(int i=0; i<q; i++) {
			scanf("%d %d %d", &l[i], &r[i], &rmq[i]);
		}
		int pos[q];
		for(int i=0; i<q; i++) {
			pos[i]=i;
		}
		sort(pos, pos+q, comp);

		for(int i=0; i<q; i++) {
			int ipos = pos[i];
			int L=l[ipos], R=r[ipos], RMQ=rmq[ipos];
			while(L<=R) {
				arr[L]=RMQ;
				L++;
			}
		}
		printf("Case %d:", tst++);
		for(int i=1; i<=n; i++) {
			
			printf(" %d", arr[i]);
		}
		puts("");
	}
}
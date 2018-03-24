#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace std;
using namespace __gnu_pbds;

#define pii pair<int, int>

typedef
tree<
  pii,
  null_type,
  less<pii>,
  rb_tree_tag,
  tree_order_statistics_node_update>
BST;

int cnt[15007];

int main() {
	BST bst;

	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int level = bst.order_of_key(make_pair(x+1, -1));
		cnt[level]++;
		bst.insert(make_pair(x, i));
	}

	for(int i=0; i<n; i++) {
		printf("%d\n", cnt[i]);
	}
}

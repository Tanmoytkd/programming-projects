#include <bits/stdc++.h>
using namespace std;
#define mx 65536
int leftchild[mx], rightchild[mx], parent[mx], isright[mx], isleft[mx], current;

int dfs(int node) {
	if(rightchild[node]!=-1) dfs(rightchild[node]);
	if(leftchild[node]!=-1) dfs(leftchild[node]);
	printf("%d\n", node);
}

void insert(int node, int val) {
	if(val<node) {
		if(leftchild[node]==-1) {

			//cout << node << " " << val << endl;

			leftchild[node]= val;
			parent[val]=node;
			isleft[val]=1;
			current=val;
		}
		else insert(leftchild[node], val);
	}
	else if(val>node) {	
		if(rightchild[node]==-1) {
			
			//cout << node << " " << val << endl;

			rightchild[node]=val;
			parent[val]=node;
			isright[val]=1;
			current=val;
		}
		else insert(rightchild[node], val);
	}
}

int main() {
	
	memset(leftchild, -1, sizeof leftchild);
	memset(rightchild, -1, sizeof rightchild);

	

	int n;
	scanf("%d", &n);

	if(n==0) {
	 	return 0;
	}

	int root;

	int arr[n];

	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}

	reverse(arr, arr+n);

	root = arr[0];
	isright[root]=1;
	isleft[root]=1;
	parent[root]=root;
	current=root;

	for(int i=1; i<n; i++) {
		int val=arr[i];
		while(current!=root && ( (val>current && val>parent[current]) || (val<current && val<parent[current]))) {
			current=parent[current];
		}


		insert(current, val);
	}

	dfs(root);
}
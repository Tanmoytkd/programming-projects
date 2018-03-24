#include <bits/stdc++.h>
using namespace std;
#define mx 100007
#define mod 10007
struct parabola {
	int a, b, c;
	parabola() {
		a=0;
		b=0;
		c=0;
	}

	parabola(int x, int y, int z) {
		a=x%mod;
		b=y%mod;
		c=z%mod;
	}

	parabola operator+(parabola x) {
		return parabola(a+x.a, b+x.b, c+x.c);
	}

	parabola operator+=(parabola x) {
		a+=x.a;
		a%=mod;
		b+=x.b;
		b%=mod;
		c+=x.c;
		c%=mod;
	}

	bool operator==(parabola x) {
		return a==x.a && b==x.b && c==x.c;
	}

	bool operator!=(parabola x) {
		return !(operator==(x));
	}
};

parabola tree[mx*4], lazy[mx*4];
int sqrtotal[mx], sumtotal[mx];

int total(int *arr, int start, int finish) {
	if(start==0) {
		return (arr[finish]);
	}
	return ((arr[finish]-arr[start-1])%mod+mod)%mod;
}

parabola calculate(int start, int finish, int a, int b, int c) {
		int sqr = (total(sqrtotal, start, finish)*a)%mod;
		int single = (total(sumtotal, start, finish)*b)%mod;
		int constant = ((finish-start+1)*c)%mod;
		return parabola(sqr, single, constant);
}

void update(int node, int start, int finish, int l, int r, int a, int b, int c) {
	parabola para(a,b,c);
	int mid = (start+finish)/2;
	int left = node*2;
	int right = left+1;

	if(lazy[node]!=parabola()) {
			
		if(start!=finish) {
			lazy[left]+=lazy[node];
			tree[left]+=calculate(start, mid, lazy[node].a, lazy[node].b, lazy[node].c);
			lazy[right]+=lazy[node];
			tree[right]+=calculate(mid+1, finish, lazy[node].a, lazy[node].b, lazy[node].c);
			lazy[node]=parabola();
		}
	}

	
	if(start>r || finish<l) {
		return;
	}
	if(start>=l && finish<=r) {
		tree[node]+=calculate(start, finish, a, b, c);
		lazy[node]+=para;
		return;
	}

	update(left, start, mid, l, r, a, b, c);
	update(right, mid+1, finish, l, r, a, b, c);

	tree[node]=tree[left]+tree[right];
}

int query(int node, int start, int finish, int l, int r) {
	int mid = (start+finish)/2;
	int left = node*2;
	int right = left+1;

	
	if(lazy[node]!=parabola()) {
			
		if(start!=finish) {
			lazy[left]+=lazy[node];
			tree[left]+=calculate(start, mid, lazy[node].a, lazy[node].b, lazy[node].c);
			lazy[right]+=lazy[node];
			tree[right]+=calculate(mid+1, finish, lazy[node].a, lazy[node].b, lazy[node].c);
			lazy[node]=parabola();
		}
	}

	if(start>r || finish<l) {
		return 0;
	}
	if(start>=l && finish<=r) {
		//cout << start <<  " - " << finish << ": ";
		//cout << tree[node].a << " " << tree[node].b << " " << tree[node].c << endl;
		
		// //cout << sqr << " " << single << " " << constant << endl;;
		return (tree[node].a + tree[node].b + tree[node].c)%mod;
	}

	return (query(left, start, mid, l, r)+query(right, mid+1, finish, l, r))%mod;
}

int sieve() {
	for(int i=1; i<mx; i++) {
		sqrtotal[i]=sqrtotal[i-1];
		sqrtotal[i]+=(i%mod)*(i%mod);
		sqrtotal[i]%=mod;
	
		sumtotal[i]=sumtotal[i-1];
		sumtotal[i]+=i;
		sumtotal[i]%=mod;
	}
}

int main() {
	sieve();


	int n, m;
	scanf("%d%d", &n, &m);

	for(int i=0; i<m; i++) {
		int action;
		scanf("%d", &action);

		if(action==0) {
			int l, r, a, b, c;
			scanf("%d%d%d%d%d", &l, &r, &a, &b, &c);
			update(1, 0, n-1, l, r, a, b, c);
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", query(1, 0, n-1, l, r));
		}

	}
	return 0;
}
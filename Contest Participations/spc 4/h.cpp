#include <bits/stdc++.h>
using namespace std;
#define mx 1000000

char mark[mx+7], mag[mx+7];
int N, Q;

void seive() {
    for(int i=4; i<=mx; i+=2) mark[i]=1;
    int stop=sqrt(mx);
    for(int i=3; i<=stop; i+=2) {
        if(mark[i]) continue;
        for(int j=i*i; j<=mx; j+=i+i) {
            mark[j]=1;
        }
    }
}

int isprime(int n) {
    return !mark[n];
}

vector<int> magical;
queue<int> prime, nonprime;

void gen(int val) {
    //cout << val << endl;
    if(val>1000000) return;
    mag[val]=1;
    magical.push_back(val);

    int lastdig = val%10;
    if(lastdig!=9)
        gen(val*10+lastdig+1);
    if(lastdig!=0)
        gen(val*10+lastdig-1);
}

void igen() {
    prime=queue<int>();
    nonprime=queue<int>();
    for(int i=0; i<magical.size(); i++) {
        int val=magical[i];
        if(val>N) break;
        if(isprime(val)) prime.push(val);
        else nonprime.push(val);
    }
}

struct pii {
    int val, cnt;

    pii() {
        val=0, cnt=0;
    }
    pii(int a, int b) {
        val=a, cnt=b;
    }

    pii operator+ (pii b) {
        pii res;
        res.val = val+b.val;
        res.cnt = cnt+b.cnt;
        return res;
    }
} tree[mx*4];;

pii build(int node, int start, int fin) {
    if(start==fin) {
    	int val=start-1;
        tree[node].val=val;
        if(mag[val]) tree[node].cnt=1;
        else tree[node].cnt=0;

        //cout << "Node-val: " << node << " (" << start << " " << fin << ") :" << val << endl;

        return tree[node];

    }

    int left = node*2, right=left+1;
    int mid=(start+fin)/2;

    pii x=build(left, start, mid);
    pii y=build(right, mid+1, fin);
    tree[node]=x+y;
    return tree[node];
}

pii update(int node, int start, int fin, int index) {
	//cout <<"index = " << index << endl;
    if(fin<index || start>index) {
    	return tree[node];
    }
    if(start==index && fin==index) {
        if(tree[node].cnt==0) {
            tree[node].cnt=1;
            int val=tree[node].val;
            //cout << "Node-val: " << node << " (" << start << " " << fin << ") :" << val << endl;
            //cout << "VAL = " << val << endl;

            queue<int> q;
            if(isprime(val)) q=prime;
            else q=nonprime;

            while(q.size()>1 && q.front()<=val) q.pop();

            tree[node].val=q.front();
            //cout << "Newval = " << tree[node].val << endl;
        }
        return tree[node];
    }

    int left=node*2, right=left+1;
    int mid=(start+fin)/2;

    pii x=update(left, start, mid, index);
    pii y=update(right, mid+1, fin, index);

    tree[node]=x+y;
    return tree[node];
}

pii query(int node, int start, int fin, int x, int y) {
    if(fin<x || start>y) return pii();
    if(start>=x && fin<=y) return tree[node];

    int left=node*2, right=left+1;
    int mid=(start+fin)/2;

    pii r1=query(left, start, mid, x, y);
    pii r2=query(right, mid+1, fin, x, y);

    return r1+r2;
}


int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    seive();
    for(int i=1; i<=9; i++) gen(i);
    magical.push_back(0);
	mag[0]=1;
    sort(magical.begin(), magical.end());

    int t;
    cin >> t;

    while(t--) {
        cin >> N >> Q;
        igen();
        int magcnt = build(1, 1, N+1).cnt;


        while(Q--) {
             int action, x, y;
             cin >> action >> x;
             if(action==1) cin >> y;

             //if(action==2) cout << "Action : " <<  action << " " << x << endl;

             if(action==1) {
                pii ans = query(1, 1, N+1, x, y);
                cout << ans.cnt << " " << ans.val << endl;
             }
             else
                magcnt=update(1, 1, N+1, x).cnt;
        }

        if(magcnt>(N-magcnt)) cout << "happy" << endl;
        else cout << "unhappy" << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct query {
    int start, finish, type;

    query(int a, int b, int c) {
        start=a;
        finish=b;
        type=c;
    }
};

int n, q;
int tree[1500000], total[1500000], arr[1500000], lazy[1500000];
vector<query> que;
set<int> st;
vector<int> positions;
int N;

void build(int node, int start, int finish) {
//    cout << "build: " << node << " " << start << " " << finish << endl;
//    getchar();
//    getchar();

    if(start==finish) {
        tree[node]=arr[start];
        total[node]=arr[start];
        return;
    }

    int mid = (start+finish)/2;

    int left = node*2;
    int right = left+1;

    build(left, start, mid);
    build(right, mid+1, finish);

    tree[node]=tree[left]+tree[right];
    total[node]=tree[left]+tree[right];
}



int turnOff(int node, int l, int r, int start=1, int finish=N) {
    //out << "turnOff: " << node << " " << l << " " << r << " " << start << " " << finish << endl;
    int mid = (start+finish)/2;
    int left = node*2;
    int right = left+1;

    if(lazy[node]) {
        if(start!=finish) {
            lazy[left]=lazy[node];
            lazy[right]=lazy[node];

            tree[left] = (lazy[node]==1) ? 0:total[left];
            tree[right]= (lazy[node]==1) ? 0:total[right];
        }
        lazy[node]=0;
    }

    if(start>r || finish<l) {
        return tree[node];
    }

    if(start>=l && finish<=r) {
        lazy[node]=1;
        tree[node]=0;
        return tree[node];
    }

    turnOff(left, l, r, start, mid);
    turnOff(right, l, r, mid+1, finish);

    tree[node]=tree[left]+tree[right];
    return tree[node];
}

int turnOn(int node, int l, int r, int start=1, int finish=N) {
    int mid = (start+finish)/2;
    int left = node*2;
    int right = left+1;

    if(lazy[node]) {
        if(start!=finish) {
            lazy[left]=lazy[node];
            lazy[right]=lazy[node];

            tree[left] = (lazy[node]==1) ? 0:total[left];
            tree[right]= (lazy[node]==1) ? 0:total[right];
        }
        lazy[node]=0;
    }

    if(start>r || finish<l) {
        return tree[node];
    }

    if(start>=l && finish<=r) {
        lazy[node]=2;
        tree[node]=total[node];
        return tree[node];
    }

    turnOn(left, l, r, start, mid);
    turnOn(right, l, r, mid+1, finish);

    tree[node]=tree[left]+tree[right];
    return tree[node];
}


int index(int number) {
//    cout << "find :" << number << endl;
//    for(int i=0; i<positions.size(); i++) {
//        cout << positions[i] << " ";
//    }
//    cout << endl;
    int ret = upper_bound(positions.begin(), positions.end(), number)-positions.begin();
    //cout << "found at: " << ret << endl;
    return ret;
}

int main() {
    scanf("%d%d", &n, &q);


    st.insert(1);
    st.insert(n+1);

    for(int i=0; i<q; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        st.insert(a);
        st.insert(b+1);

        que.push_back(query(a,b,c));
    }


    positions = vector<int>(st.begin(), st.end());
    N=positions.size()-1;
    for(int i=1; i<positions.size(); i++) {
        arr[i]=positions[i]-positions[i-1];
        //cout << i << " " << arr[i] << endl;
    }

//    cout << st.size() << endl;
//    cout << N << endl;
    build(1, 1, N);

    for(int i=1; i<=N; i++) {
        //cout << "TkD " << positions[i] << endl;
        //cout << "RmE " << i << " " << arr[i] << endl;
    }

    for(int i=0; i<que.size(); i++) {
        int type = que[i].type;
        if(type==1) {
            //cout << "off:" << index(que[i].start) << " " << index(que[i].finish) << endl;
            cout << turnOff(1, index(que[i].start), index(que[i].finish)) << endl;
        }
        else {
//            cout << "on:" << que[i].start << " " << que[i].finish << endl;
            cout << turnOn(1, index(que[i].start), index(que[i].finish)) << endl;
        }
    }

//    cout << index(n+1) << endl;
    return 0;
}

/*
500000
1
196303 288435 1
*/

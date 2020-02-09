#include <bits/stdc++.h>
using namespace std;
#define mx ((int)(2*2e5+7))

struct seg{
    int start, finish, id;

    friend bool operator< (const seg& a, const seg& b);
    friend bool operator== (const seg& a, const seg& b);
};

bool operator== (const seg& a, const seg& b) {
    return a.start==b.start && a.finish==b.finish;
}

bool operator< (const seg& a, const seg& b) {
    if(a.start<b.start) return true;
    if(a.start>b.start) return false;
    if(a.finish<b.finish) return true;
    if(a.finish>b.finish) return false;
    return false;
}

struct node {
    int num;
    bool isStart;

    friend bool operator< (const node &a, const node &b);
};

bool operator< (const node &a, const node &b) {
    return make_tuple(a.num, !a.isStart)<make_tuple(b.num, !b.isStart);
}

set<node> corners;
map<node, int> pos;

vector<int> tree[mx*4];
int arr[mx];
bool mark[mx];

void build(int node, int start, int finish) {
    tree[node] = vector<int>();
    if(start==finish) {
        if(mark[start]) tree[node].push_back(arr[start]);
        return;
    }
    int left = node*2;
    int right = left+1;
    int mid = (start+finish)/2;

    build(left,start, mid);
    build(right, mid+1, finish);

    merge(tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter(tree[node]) );
}

int query(int node, int start, int finish, int l, int r) {
    if(start>r || finish<l) {
        return upper_bound(tree[node].begin(), tree[node].end(), 1)-lower_bound(tree[node].begin(), tree[node].end(), 1);
    }
    if(start>=l && finish<=r) {
        return upper_bound(tree[node].begin(), tree[node].end(), 2)-lower_bound(tree[node].begin(), tree[node].end(), 2);
    }

    int left = node*2;
    int right = left+1;
    int mid = (start+finish)/2;

    return query(left, start, mid, l, r) + query(right, mid+1, finish, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        corners.clear();
        pos.clear();


        int n;
        cin >> n;

        vector<seg> segments(n+1);

        for(int i=1; i<=n; i++) {
            int l, r;
            cin >> l >> r;
            corners.insert({l, true});
            corners.insert({r, false});
            segments[i]= {l, r, i};
        }

        sort(segments.begin()+1, segments.end());

        int index = 1;
        for(auto it=corners.begin(); it!=corners.end(); it++) {
            pos[*it] = index;
            if(it->isStart) mark[index]=true;
            index++;
        }

//        int treesize = pos.size()*4;
//        for(int i=1; i<=treesize; i++) {
//            tree[i].clear();
//        }

        vector<tuple<int,bool,int>> points;

//        cout << "----------" << endl;
        for(int i=1; i<=n; i++) {
            segments[i].start = pos[{segments[i].start, true}];
            segments[i].finish = pos[{segments[i].finish, false}];

            if(!(segments[i]==segments[i-1])) {
                points.push_back(make_tuple(segments[i].start, !true, i));
                points.push_back(make_tuple(segments[i].finish, !false, i));
//                cout << "pushed - ";
            }

//            cout << /*i << " " << */ segments[i].start << " " << segments[i].finish << endl;
//            update(1, 1, pos.size(), segments[i].start, segments[i].finish, 1);
        }
//        cout << "----------" << endl;

        sort(points.begin(), points.end());
        set<tuple<int,int,int>> st;
        for(auto pnt: points) {
            int num, id;
            bool isfinish;
            tie(num, isfinish, id) = pnt;

//            cout << num << " " << isfinish << " " << id << endl;

            if(!isfinish) {
                st.insert(pnt);
                arr[num] = st.size();
            } else {
                arr[num]=max(arr[num], (int) st.size());
                st.erase(make_tuple(segments[id].start,false,id));
            }
        }

//        cout << "--------" << endl;

        int sz = pos.size();
//        cout << " sz: " << sz << " " << points.size() << endl;

        build(1, 1, sz);

        int res = 0;

        for(int i=1; i<=n; i++) {
            int q;
            if(segments[i]==segments[i-1]) {
                q = query(1, 1, pos.size(), -1, -1);
            }
            else {
                q = query(1, 1, pos.size(), segments[i].start, segments[i].finish);
            }
            res = max(res, q);
        }

//        cout<< tree[1].size() << endl;

//        for(int i=1; i<=sz; i++) {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
        memset(arr, 0, sizeof(int)*(sz+1));
        memset(mark, 0, sizeof(int)*(sz+1));

        cout << res << endl;

    }
    return 0;
}

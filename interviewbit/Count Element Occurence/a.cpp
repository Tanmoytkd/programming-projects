int upper_bound(const vector<int> &v, int num, int st, int fn) {
    int res = fn;
    if (st < fn) {
        int mid = (st + fn) / 2;
        
        if (v[mid] <= num) {
            res = upper_bound(v, num, mid+1, fn);
        } else {
            res = upper_bound(v, num, st, mid);
        }
    }
    return res;
}

int lower_bound(const vector<int> &v, int num, int st, int fn) {
    int res = fn;
    if (st < fn) {
        int mid = (st + fn) / 2;
        
        // cout << mid << " " << v[mid] << endl;
        
        if (v[mid] < num) {
            res = lower_bound(v, num, mid+1, fn);
        } else {
            res = lower_bound(v, num, st, mid);
        }
    }
    return res;
}

int Solution::findCount(const vector<int> &A, int B) {
    
    long long u = upper_bound(A, B, 0, A.size()), l = lower_bound(A, B, 0, A.size());
    // cout << u << ' ' << l << endl;
    return u - l;
}

bool comp(int n) {
    if (n < 2) return true;
    if (n == 2) return false;
    if (n % 2 == 0) return true;
    
    
    for (int i = 3; i*i<=n; i+=2) {
        if (n % i == 0) {
            return true;
        }
    }
    return false;
}

vector<int> Solution::primesum(int A) {
    vector<int> res;
    
    //seive(comp, A);
    
    
    if (!comp(A-2)) {
        res.push_back(2);
        res.push_back(A-2);
        return res;
    }

    for (int i = 3; i < A; i += 2) {
        if (!comp(i) && !comp(A-i)) {
            res.push_back(i);
            res.push_back(A-i);
            return res;
        }
    }
}

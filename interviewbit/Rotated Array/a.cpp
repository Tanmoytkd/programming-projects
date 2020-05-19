int Solution::findMin(const vector<int> &a) {
    int st = 0, fn = a.size()-1;
    while (st <= fn) {
        int mid = (st+fn)/2;
        
        if (st == fn) {
            return min(a[st], a[0]);
        }
        
        if (a[mid]<a[0]) {
            fn = mid;
        } else if(a[mid]>a[0]) {
            st = mid + 1;
        }
    }
    return a[0];
}

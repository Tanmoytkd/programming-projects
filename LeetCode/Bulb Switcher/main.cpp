#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        else {
            //bool arr[n]= {false};
            vector<bool> arr;
            arr.resize(n, false);

            for(int i=1; i<=n; i++) {
                for(int j=i; j<=n; j+=i) {
                    //toogle(arr[j-1]);
                    arr[j-1] = (arr[j-1]==false) ? true:false;
                }
            }

            int count=0;
            for(int k=0; k<n; k++) {
                if(arr[k]==true) count++;
            }
            return count;
        }
    }

    /*void toogle(bool &value) {
        value = (value==false) ? true:false;
    }*/
};

int main()
{
    Solution so;
    int s=0;
    cin >> s;
    cout << "\n" << so.bulbSwitch(s) << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        else {
            //int arr[n]= {0};
            vector<int> arr;
            arr.resize(n, 0);

            /*for(int l1=0; l1<n; l1++) {
                cout << arr[l1];
            }
            cout << endl;*/

            for(int i=1; i<=n; i++) {
                for(int j=i; j<=n; j+=i) {
                    arr[j-1] = (arr[j-1]==0) ? 1:0;
                }
                /*for(int l1=0; l1<n; l1++) {
                    cout << arr[l1];
                }
                cout << endl;*/
            }


            int count=0;
            for(int k=0; k<n; k++) {
                cout << k+1 << "==>" << arr[k] << endl;
                if(arr[k]==1) count++;
            }
            return count;
        }
    }

    /*void toogle(int &value) {
        value = (value==0) ? 1:0;
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

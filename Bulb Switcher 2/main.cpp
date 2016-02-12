#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        else {
            //bool arr[n]= {false};
            vector<int> arr;
            arr.resize(n, 1);
            vector<int> primes;

            int counter=1;

            for(int i=2; i<=n; i++) {
                int value = arr[i-1];
                if(value==1) {
                    primes.push_back(i);
                    arr[i-1] = 2;
                    value = 2;
                }
                cout << "Value = " << value << endl;


                counter += value%2;
                cout << "counter = " << counter << endl;


                int psize = primes.size();
                if(psize>0) {
                    for(int m=0; m<psize; m++) {
                        int pos = i*primes[m]-1;
                        if(pos<n) {
                            arr[pos] = value+1;
                        }
                    }
                }
            }
            return counter;

            /*for(int i=1; i<=n; i++) {
                for(int j=i; j<=n; j+=i) {
                    //toogle(arr[j-1]);
                    arr[j-1] = (arr[j-1]==false) ? true:false;
                }
            }*/

            /*int count=0;
            for(int k=0; k<n; k++) {
                if(arr[k]==true) count++;
            }
            return count;*/
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
    //for(int i=0; i<=s; i++) {
        cout << "\n" /*<< i << "    "*/ << so.bulbSwitch(s) << endl;
    //}
    return 0;
}

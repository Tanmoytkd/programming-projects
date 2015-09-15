#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int finalpos = size-1;
        digits[finalpos] = digits[finalpos] + 1;
        while(finalpos!=0) {
                if(digits[finalpos]>=10) {
                    digits[finalpos] -= 10;
                    finalpos--;
                    digits[finalpos]++;
                }
                else {
                    finalpos = 0;
                }

        }


        int val = digits[0];
        if(val >= 10) {
            int lastval = val/10;
            digits.insert(digits.begin(), lastval);
            digits[1] = val-10;
        }

        return digits;
    }
};

int main()
{
    Solution so;
    vector<int> nums = {1,0};
    vector<int> sol =  so.plusOne(nums);
    for(unsigned int i=0; i<sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}

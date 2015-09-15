// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::vector<int>::iterator pos = std::find(nums.begin(), nums.end(), val);
        std::vector<int>::iterator end = nums.end();

        while(pos != end) {
	        nums.erase(pos);
	        end = nums.end();
        	pos = std::find(pos, end, val);
        }
        return nums.size();
    }
};

int main()
{
  vector<int> vct;
  vct.push_back(1);
  vct.push_back(2);
  int val = 1;
  Solution so;
  cout << so.removeElement(vct, val) << endl;
}

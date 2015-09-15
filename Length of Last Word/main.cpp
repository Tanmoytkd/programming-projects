#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        int count = 0;
        while(s[size-1] == ' ') {
            s = s.substr(0, size-1);
            size--;
        }

        for(int i=size-1; i>=0; i--) {
            if(s[i] == ' ') {
                break;
            }
            else {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    string s="a  ";
    Solution so;

    cout << so.lengthOfLastWord(s) << endl;
    return 0;
}

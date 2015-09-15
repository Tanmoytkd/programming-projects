#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int size = s.length();
        bool check[size]; //create checker array
        for(int i=0; i<size; i++) { //set checker aray
            check[i] = false;
        }

        bool res = true;

        for(int j=0; j<size && check[j] == false; j++) { //character replacement
            string c1 = s.substr(j,1); //get the character at j
            string c2 = t.substr(j,1); //get the character at j

            if(c2 == "|") {
                    res = false;
            }

            int spos, tpos;
            while(s.find(c1) != std::string::npos && c1 != "|") { //as long as there is c1 in s
                spos = s.find(c1);
                check[spos] = true;
                s.replace(spos, 1, "|");
                cout << "s : " << s << endl;
                if(t.substr(spos, 1) != c2) {
                        res = false;
                        cout << "t : " << t << endl;
                        cout << "res : " << res << endl;

                }
                else {
                    cout << "t : " << t << endl;
                    cout << "res : " << res << endl;
                    while(t.find(c2) != std::string::npos && c2 != "|") {
                        cout << "c2 : " << c2 << endl;
                        tpos = t.find(c2);
                        t.replace(tpos, 1, "|");
                    }
                }
            }

        }

        return res;
    }
};

int main()
{
    Solution so;
    cout << so.isIsomorphic("ab", "aa") << endl;
    return 0;
}

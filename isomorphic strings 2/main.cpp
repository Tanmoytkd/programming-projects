#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) {
            cout << "These strings are not of the same length. Please restart the program and try again. Arguments are ";
            return false;
        }
        int size = s.length();
        //char s1[size];
        //char t1[size];
        string avails = "";
        string availt = "";
        avails += s[0];
        availt += t[0];
        int maxnums=0, maxnumt=0;

        for(int i=0; i<size; i++) {
            unsigned int spos = avails.find(s[i]);
            if(spos == std::string::npos) {
                maxnums++;
                spos = maxnums;
                avails += s.substr(i, 1);
            }
            cout << spos << " ";
            //s1[i] = (char) spos;
            //cout << s1[i] << " ";


            unsigned int tpos = availt.find(t[i]);
            if(tpos == std::string::npos) {
                maxnumt++;
                tpos = maxnumt;
                availt += t.substr(i, 1);
            }
            cout << tpos << endl;
            //t1[i] = (char) tpos;
            //cout << t1[i] << endl;

            if(spos != tpos) {
                //cout << endl << "Non-Isomorphic at the (nth) character: " << i+1 << endl;
                return false;
            }
        }

        return true;
        /*string strs(s1);
        cout << endl << strs << endl;
        string strt(t1);
        cout << strt << endl;
        if(strs == strt) {return true;}
        else {return false;}*/
    }
};

int main()
{
    string s="baa", t="cfa";
    cout << "Please enter the first string: ";
    cin >> s;
    cout << "\nEnter the second string: ";
    cin >> t;
    Solution so;
    bool res = so.isIsomorphic(s,t);
    if(res == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}

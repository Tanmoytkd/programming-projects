#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

string to_string(int x) {
    stringstream ss;
    ss << x;
    return ss.str();
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<int> size;
        vector<int> sizednums;

        for(int counter=0; counter<nums.size(); counter++) {
            cout << nums[counter] << " ";
        }
        cout << "\n" << endl;

        for(unsigned int i = 0; i<nums.size(); i++) {
            int num = nums[i];
            int itssize;
            if(num == 0) {itssize = 1;}
            else {itssize = 0;}
            while(num) {
                itssize++;
                num /=10;
            }
            //cout << nums[i] << "'s size is " << itssize << endl;
            size.push_back(itssize);
        }

        int numsize = nums.size();

        for(int m=0; m<numsize; m++) {
            for(int n=m+1; n<numsize; n++) {
                if(shouldswap(nums[m], size[m], nums[n], size[n])) {
                    int temp = nums[m];
                    nums[m] = nums[n];
                    nums[n] = temp;

                    temp = size[m];
                    size[m] = size[n];
                    size[n] = temp;
                }
            }
        }
        if(zerocheck(nums)) return "0";

        string stringnum="";
        for(unsigned int o=0; o<nums.size(); o++) {
            stringnum += to_string(nums[o]);
        }

        return stringnum;
    }
    bool zerocheck(vector<int> &nums) {
        int size = nums.size();
        for(int i=0; i<size; i++) {
            if(nums[i] != 0) return false;
        }
        return true;
    }
    int pow10(int n) {
        int res = 1;
        for(int i=0; i<n; i++) {
            res *= 10;
        }
        return res;
    }
    bool shouldswap(int inum,int isize,int jnum,int jsize) {
        string blank;
        int calcsize = 0, maxsize = (isize>jsize) ? isize:jsize;
        do {
            int x, y;
            //cout << inum << " " << jnum << endl;
            //cout <<"isize: " << isize << "; jsize: " << jsize << "; ";
            if(isize>jsize) {
                int size = jsize, power=pow10(isize-size);
                x=inum/power;
                y=jnum;
                calcsize +=size;
                inum = inum%power;
                isize = isize-size;
                //cout << "size: " << size << "; Power: " << power << endl;
                //cout <<"x: " << x << ", ";
                //cout <<"y: " << y << endl;
                //cout << "isize>jsize" << endl;
                //cout << "isize: " << isize << endl;
                //cin >> blank;
            }
            else if(isize<jsize) {
                int size = isize, power=pow10(jsize-size);
                x=inum;
                y=jnum/power;
                calcsize +=size;
                jnum = jnum%power;
                jsize = jsize-size;
                //cout << "size: " << size << "; Power: " << power << endl;
                //cout <<"x: " << x << ", ";
                //cout <<"y: " << y << endl;
                //cout << "isize<jsize" << endl;
                //cout << "jsize: " << jsize << endl;

                //cin >> blank;
            }
            else {
                int size = isize;
                x=inum;
                y=jnum;
                calcsize +=size;
                //cout << "size: " << size << endl;
                //cout <<"x: " << x << ", ";
                //cout <<"y: " << y << endl;
                //cout << "isize = jsize" << endl;
            }

            if(x<y) {
                    //cout << "result : true" << endl;
                    return true;
                }
                else if(x>y) {
                    return false;
                }
        }while(calcsize <= maxsize);
        //cout << "result : false" << endl;
        return false;
    }
};

int main()
{
    Solution so;
    vector<int> d = {3, 30, 34, 5, 9};
    vector<int> dd = {22229, 22};
    vector<int>ddd = {121,12};
    vector<int>dddd = {1,2,3,4,5,6,7,8,9,0};
    vector<int>ddddd = {20, 1};
    vector<int>dddddd = {19122, 15688, 4403};
    vector<int> data = {999999998,999999997,999999999};


    vector<int> example;
    srand(time(0));
    for(int i=0; i<100; i++) {
        example.push_back(rand());
    }
    string sol = so.largestNumber(data);
    cout << sol << endl;
    return 0;
}

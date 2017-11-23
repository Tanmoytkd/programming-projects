#include <iostream>
#include <sstream>
using namespace std;

//int summ(int x, int y);

class calculator{
    public:
        void conv(int x, int y) {
            a = float(x);
            b = float(y);
        }
        int sum(int x, int y) {
            a=0;b=0;
            res = 0;
            conv(x,y);
            res=a+b;
            return res;
        }
        int diff(int x, int y) {
            a=0;b=0;
            res = 0;
            conv(x,y);
            if(x>y) {
                res=a-b;
                return res;
            }
            else {
                res=b-a;
                return res;
            }
        }
        int multi(int x, int y) {
            a=0;b=0;
            res = 0;
            conv(x,y);
            res=a*b;
            return res;
        }
        string div(int x, int y) {
            a=0;b=0;
            res = 0;
            if(y==0) return "Can not be divided by zero";
            else {
                conv(x,y);
                res = a/b;
                stringstream ss;
                ss << res;
                result = "The divition of the numbers is " + ss.str();

                //string result = "The divition of the numbers is " + res;
                return result;
            }
        }
    private:
        float a, b, res;
        stringstream ss;
        string result;
};

int main()
{
    int x, y;
    cout << "Enter the first number: " ;
    cin >> x;
    cout << "Enter the second number: " ;
    cin >> y;

    calculator calobj;

    cout << "\nThe sum of the numbers is " << calobj.sum(x,y) << "\n" << endl;
    cout << "\nThe difference of the numbers is " << calobj.diff(x,y) << "\n" << endl;
    cout << "\nThe multiplication of the numbers is " << calobj.multi(x,y) << "\n" << endl;
    cout << "\n" << calobj.div(x,y) << "\n" << endl;

    return 0;
}

/*int summ(int x, int y) {
    return x+y;
}
*/

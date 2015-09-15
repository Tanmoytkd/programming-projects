#include <iostream>
#include <string>
using namespace std;

class var {
    string val;
    public:
        var(string value) {
            val = value;
        }

        string data() {
            return val;
        }
};

int main()
{
    var month = {"January"};
    cout << month.data() << endl;
    return 0;
}

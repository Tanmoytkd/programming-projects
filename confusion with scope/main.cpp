#include <iostream>

using namespace std;

class hanna {
public:
    void printCrap() {
        int h = 365;
        cout << h << endl;
        cout << this->h << endl;
        cout << (*this).h << endl;
    }
private:
    int h=999;
};

int main()
{
    hanna ho;
    ho.printCrap();
    return 0;
}

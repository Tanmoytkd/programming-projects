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
    //ho.printCrap(); //works perfectly, but I disabled it because I don't need it.
    hanna *pho = &ho;
    (*(&ho)).printCrap(); //first I got the memory address from &ho, then converted it to a pointer by *(&ho)
                          //and then I dereferenced it with (*(&ho)) then I used the member function printCrap()
    return 0;
}

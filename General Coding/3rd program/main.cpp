#include <iostream>

using namespace std;

class adder{
    public:
        adder(int x) {
            total=x;
        }
        void add(int x) {
            total=total+x;
        }
        int getResult() {
            return total;
        }
    private:
        int total;

};

int main()
{
    int number;
    adder sum(0);
    for(int x=0; x<5; x++) {
        cout << "Enter a number: ";
        cin >> number;
        sum.add(number);
    }
    cout << "The total of the numbers is " << sum.getResult() << endl;
    return 0;
}

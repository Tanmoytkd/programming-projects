#include <iostream>

using namespace std;

class example {
    public:
        example(int a, int b)
        :i(a), l(b)
        {
        }

        int* geti() {
            return &i;
        }

        const int* getl() {
            return &l;
        }
    private:
        int i;
        const int l;
};

int main()
{
    int i1, l1;

    cout << "Please enter the value of i: ";
    cin >> i1;
    cout << endl;

    cout << "Please enter the value of l: ";
    cin >> l1;
    cout << endl;

    example e(i1,l1);

    int *iloc=e.geti();
    const int *lloc=e.getl();

    cout << "Enter the new value of i: ";
    cin >> i1;
    *iloc=i1;
    cout << endl;



    cout << "i=" << *iloc << "; l=" << *lloc << ";" << endl;

    cout << "\n\nHere l is an constant member variable of the class. So it can not be changed" << endl;

    return 0;
}

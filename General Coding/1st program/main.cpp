#include <iostream>

using namespace std;

void printResult(int sum, int diff, int multi);

int main()
{
    int a,b;

    cout << "Hello world!" << endl;
    cout << "I am Tanmoytkd. This is my first c++ program";
    cout << " and I am enjoying making it\n\nIt is awesome" << endl;

    cout << "Let's see a calculation \n";

    cout << "Enter a number:\n";
    cin >> a;
    cout << "Enter another number:\n";
    cin >> b;

    int sum = a+b;
    int diff;

    if(a>b) diff = a-b;
    else diff = b-a;

    int multi = a*b;

    printResult(sum, diff, multi);

    return 0;
}

void printResult(int sum, int diff, int multi) {
cout << "\n\nThe summation of the numbers is " << sum
    << ";\n The difference between the numbers is " << diff
    << ";\n The multiplication of the numbers is " << multi << ";" << endl;
}

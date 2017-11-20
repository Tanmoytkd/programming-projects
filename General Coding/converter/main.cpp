#include <iostream>
#include <cmath>
using namespace std;
long converter(double x) {
    return round(x);
}
int main()
{
    double x=-1.9;
    cout << converter(x) << endl;
    return 0;
}

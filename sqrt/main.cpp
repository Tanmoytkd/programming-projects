#include <iostream>
#include <cmath>
using namespace std;

template < class T >
T diff(T const& x, T const& y) {
    T res = x-y;
    return (res > 0) ?  res:(0-res);
}

double sqrts(double const& x) {
    if(x==0) {return 0;}
    double res=1;
    double divres = x/res;
    //cout << divres << endl;
    //cout << (res+divres)/2 << endl;
    while(diff(res, divres)>=0.00000000000001) {
        res = (res + divres)/2;
        divres = x/res;
        //cout << res << " " << divres << endl;
    }
    return res;
}

int main()
{
    for(int x=0; x<=100; x++) {
        //cout << sqrt (x) << endl;
        double x1= sqrt(x);
        cout << x1 << "\t" ;
        double x2= sqrts(x);
        cout << x2 << "\t" << x1-x2 << endl;
    }
    /*
    for(int x=0; x<=100; x++) {
        cout << sqrts(x) << endl;
    }
    */
    return 0;
}

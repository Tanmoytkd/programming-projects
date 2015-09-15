#include <iostream>
#include <string>
#include "person.h"
#include "Birthday.h"
using namespace std;

int setYear();
int setMonth();
int setDate(int month, int year);

int main()
{
    string name;
    cout << "Enter the name of the person: ";
    cin >> name;
    cout << endl;
    int d,m,y;

    //setting the birthday
    y=setYear();
    m=setMonth();
    d=setDate(m,y);

    Birthday bd(d,m,y);
    person p1(name, bd);

    cout << "\n" << p1.getName() << " was born on " << p1.birthday().date() << "/" << p1.birthday().month() << "/" << p1.birthday().year() << endl;
    return 0;
}

int setYear() {
    int y;
    cout << "\nPlease enter the year of birth: ";
    cin >> y;
    return y;
}

int setMonth() {
    int m, errState;
    do {
       if(errState==1) cout << "\nThe Month you entered does not exist. Please enter again." << endl;
       cout << "\nPlease enter the month of birth: ";
       cin >> m;
       errState=1;
    } while(m<1 || m>12);
    return m;
}

int setDate(int month, int year) {
    int d, maxDate, errState;
    switch(month) {
        case 1: maxDate=31; break;
        case 2: if(year%400!=0 && year%4==0) maxDate=29;
                else maxDate=28;
                break;
        case 3: maxDate=31; break;
        case 4: maxDate=30; break;
        case 5: maxDate=31; break;
        case 6: maxDate=30; break;
        case 7: maxDate=31; break;
        case 8: maxDate=31; break;
        case 9: maxDate=30; break;
        case 10: maxDate=31; break;
        case 11: maxDate=30; break;
        case 12: maxDate=31; break;
    }
    do {
        if(errState==1) cout << "\nThe date you entered does not exist. Please enter again." << endl;
        cout << "\nPlease enter the date of birth: ";
        cin >> d;
        errState=1;
    } while(d<1 || d>maxDate);

    return d;
}

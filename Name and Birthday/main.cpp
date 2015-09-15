#include <iostream>
#include <string>
#include "Birthday.h"
#include "Birthday.h"
#include "people.h"
using namespace std;

int setYear();
int setMonth();
int setDate(int month, int year);

int main()
{
    string name;
    cout << "Please enter the name of the person: ";
    cin >> name;
    cout << endl;
    int y=setYear(), m=setMonth(), d=setDate(m,y);

    Birthday bd(d,m,y);
    people person1(name, bd);

    cout << person1.getName() << " was born on " << person1.birthday().date() << "/" << person1.birthday().month() << "/" << person1.birthday().year() << endl;



    return 0;
}


int setYear() {
    int y;
    cout << "Please enter the year of birth: ";
    cin >> y;
    cout << endl;
    return y;
}

int setMonth() {
    int m, errState;
    do {
        if(errState==1) cout << "The month you entered does not exist";
        cout << "\nPlease enter the month of birth: ";
        cin >> m;
        cout << endl;
        errState=1;
    } while(m<1 || m>12);
    return m;
}

int setDate(int month, int year) {
    int d;
    int maxDate;
    switch(month) {
        case 1:
            maxDate=31; break;
        case 2: if(year%400!=0 && year%4==0) maxDate=29;
                else maxDate=28;
                break;
        case 3: maxDate=31;
        case 4: maxDate=30;
        case 5: maxDate=31;
        case 6: maxDate=30;
        case 7: maxDate=31;
        case 8: maxDate=31;
        case 9: maxDate=30;
        case 10: maxDate=31;
        case 11: maxDate=30;
        case 12: maxDate=31;
    }
    int errState;
    do {
        if(errState==1) cout << "The date you entered does not exist";
        cout << "\nPlease enter the date of birth: ";
        cin >> d;
        cout << endl;
        errState=1;
    } while(d<1 || d>maxDate);
    return d;
}

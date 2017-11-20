#include <iostream>

using namespace std;

int main()
{
    float age, ageTotal=0, numberOfPeople=0;
    cout << "Enter the age of the first person or -1 to quit:";
    cin >> age;

    while(age!=-1) {
        ageTotal=ageTotal+age;
        numberOfPeople++;

        cout << "Enter the age of the next person or -1 to quit:";
        cin >> age;
    }

    cout << "You have entered the age of " << numberOfPeople << " people." << endl;
    cout << "The average of their age is " << ageTotal/numberOfPeople << " years." << endl;
    return 0;
}

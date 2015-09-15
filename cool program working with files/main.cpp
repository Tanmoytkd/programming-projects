#include <iostream>
#include <fstream>
using namespace std;


class data{
public:
    data(int size)
    :arraySize(size)
    {
        item = new string[size];
        power = new int[size];

    }

    void setItem(int position, string value) {
        item[position] = value;
    }

    void setPower(int position, int value) {
        power[position] = value;
    }
    string getItem(int position) {
        return item[position];
    }
    int getPower(int position) {
        return power[position];
    }
    int getArraySize() {
        return arraySize;
    }

private:
    string *item;
    int *power;
    const int arraySize;

};

int getWhatTheyWant();
void printData(data do1, int whatTheyWant=1);

int main()
{
    int whatTheyWant, size;
    whatTheyWant = getWhatTheyWant();

    ifstream datafile("data.txt");

    datafile >> size;
    data do1(size);

    string item;
    int pos=0, power;
    while(datafile >> item >> power) {
        do1.setItem(pos,item);
        do1.setPower(pos, power);
        pos++;
    }



    while(whatTheyWant != 4) {
        printData(do1, whatTheyWant);
        whatTheyWant = getWhatTheyWant();
    }
    return 0;
}


int getWhatTheyWant() {
    int choice;

    cout << "Enter 1 to see all items;" << endl;
    cout << "Enter 2 to see all helpful items" << endl;
    cout << "Enter 3 to see all harmful items" << endl;
    cout << "Enter 4 to quit the program" << endl;

    cin >> choice; //get choice
    cout << endl;
    return choice;
    }



void printData(data do1, int whatTheyWant) {
    for(int i=0; i<do1.getArraySize(); i++) {
        int power = do1.getPower(i);

        switch(whatTheyWant) {
        case 1:
            cout << do1.getItem(i) << " " << power << endl;
            break;
        case 2:
            if(power>0) {
                cout << do1.getItem(i) << " " << power << endl;
            }
            break;
        case 3:
            if(power<0) {
                cout << do1.getItem(i) << " " << power << endl;
            }
        }
    }
    cout << endl;
}

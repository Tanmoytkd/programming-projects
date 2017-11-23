#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

int number_of_lines = 0;

int numberoflines(string A);
int main()
{
    cout<<numberoflines("Doctor.txt");

    getch();
    return 0;
}

int numberoflines(string A)
{
    string line;
    ifstream myfile(A.c_str());
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,line);
            number_of_lines++;
        }
        myfile.close();
    }
    return number_of_lines;
}

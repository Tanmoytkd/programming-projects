#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream inifile("initial.txt");
    string data = "abcdefg";
    inifile << data << flush;
    data = "";


    char * itsdata;
    ifstream file("initial.txt", ios::in | ios::ate | ios::binary);
    streampos itssize = file.tellg();
    cout << "The size of initial.txt is " << itssize << " bytes" << endl;
    itsdata = new char[itssize];
    file.seekg(0, ios::beg);
    file.read(itsdata, itssize);
    cout << itsdata << endl;


    inifile.close();
    file.close();
    delete [] itsdata;
    return 0;
}

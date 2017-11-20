#include <iostream>

#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

int main()
{
    string s;
    cin >> s;

    path F(s);

    if(exists(F)) cout << "Yahoo" << endl;
    else cout << "Nothing here" << endl;

    return 0;
}

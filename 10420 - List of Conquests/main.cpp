#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int test;
    string junk;
    vector<string> countries;
    cin >>  test;

    int counter[test];

    for(int i=0; i<test; i++) {
        string country;
        cin >> country;
        getline(cin, junk);

        unsigned int pos=find(countries.begin(), countries.end(), country)-countries.begin();

        if(pos==countries.size()) {
            countries.push_back(country);
            counter[pos]=1;

            while(pos>0 && countries[pos]<countries[pos-1]) {
                swap(countries[pos], countries[pos-1]);
                swap(counter[pos], counter[pos-1]);
                pos--;
            }

        }
        else {
            counter[pos]++;
        }
    }

    int vsize=countries.size();

    for(int i=0; i<vsize; i++) {
        cout << countries[i] << " " << counter[i] << endl;
    }
    return 0;
}

/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
using namespace std;

string name="Sandro";
int edit_cost=5;

int edit_price(const string& text)
{
    int coins =0;

    for (int i=0; i < name.size(); ++i)
    {
        if (isupper(text[i]) != isupper(name[i]))
        {
            coins += edit_cost;
        }

        if (toupper(text[i]) != toupper(name[i]))
        {
            coins += edit_cost;
        }
    }

    return coins;
}

int main()
{

    string manuscript;
    cin >> manuscript;

    int min_price = INT_MAX;

    for (int i= 0; i <= manuscript.size() - name.size(); ++i)
    {
        min_price = min(min_price,
                        edit_price(manuscript.substr(i, name.size())));
    }

    cout << min_price << '\n';

    return 0;
}

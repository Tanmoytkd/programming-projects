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

int main()
{

    int outflow_per_minute;
    int passed_minutes;

    sf2( outflow_per_minute, passed_minutes);

    int cars_in_traffic_jam =0;

    for (  int i {0}; i < passed_minutes; ++i)
    {
        int approaching_cars;
        sf1(approaching_cars);

        cars_in_traffic_jam += approaching_cars;
        cars_in_traffic_jam -= min(cars_in_traffic_jam, outflow_per_minute);
    }

   pf1(cars_in_traffic_jam);

    return 0;
}

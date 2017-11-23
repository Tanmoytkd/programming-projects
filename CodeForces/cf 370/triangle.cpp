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

int main() {
    int x, y;
    int tr[3];
    cin >> x >> y;
    tr[0]=tr[1]=tr[2]=y;

    int counter=0;

    while(1) {
        if(tr[0]==x && tr[1]==x && tr[2]==x) {
            cout << counter << endl;
            break;
        }
        int hand=counter%3;

        tr[hand]=tr[0]+tr[1]+tr[2]-tr[hand]-1;
        if(tr[hand]>x) tr[hand]=x;
        counter++;
    }

    return 0;
}

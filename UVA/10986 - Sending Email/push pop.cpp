#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
queue <int> Q;

int main()
{
    int i,n,m;
    while (cin >> n)
    {
        switch(n){
          case 1:
            cin >> m;
            Q.push(m);
            cout << "Q Size = " << Q.size() << endl;
            break;
          case 2:
            Q.pop();
            cout << "Q.size = " << Q.size() << endl;
            break;
          default:
            cout << "Q size = " << Q.size() << endl;
        }
    }
    return 0;
}

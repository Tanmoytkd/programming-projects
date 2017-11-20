#include<bits/stdc++.h>
#define   pf  printf
#define   sf  scanf
using namespace std;
int main()
{
    int boy,girl;
    while(sf("%d %d",&boy,&girl)==2)
    {
        if(girl>=boy)   //meye beshi
        {
            for(int i=0; i<boy; i++)
                pf("GB");
            if(girl>boy)
                for(int i=0; i<girl-boy; i++)
                    pf("G");
            pf("\n");
        }
        else   //chele beshi
        {
            for(int i=0; i<girl; i++)
                pf("BG");
            for(int i=0; i<boy-girl; i++)
                pf("B");
            pf("\n");
        }
    }

    return 0;
}

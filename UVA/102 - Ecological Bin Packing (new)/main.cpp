#include<bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
using namespace std;

#define scan_num scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &data[0][0], &data[0][2], &data[0][1], &data[1][0], &data[1][2], &data[1][1], &data[2][0], &data[2][2], &data[2][1])

int main()
{
int b1,g1,c1,b2,g2,c2,b3,g3,c3,i,a[6],min;
while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3)
    {
    a[0]=b2+b3+c1+c3+g1+g2;
    a[1]=b2+b3+c1+c2+g1+g3;
    a[2]=b1+b3+c2+c3+g1+g2;
    a[3]=b1+b2+c2+c3+g1+g3;
    a[4]=b1+b3+c1+c2+g3+g2;
    a[5]=b2+b1+c1+c3+g3+g2;
    for(i=0;i<6;i++)
        {
        if(i==0) min=a[i];
        else if(min>a[i]) min=a[i];
        }
    for(i=0;i<6;i++)
        {
        if(a[i]==min) {
                      if(i==0) cout<<"BCG ";
                      else if(i==1) cout<<"BGC ";
                      else if(i==2) cout<<"CBG ";
                      else if(i==3) cout<<"CGB ";
                      else if(i==4) cout<<"GBC ";
                      else if(i==5) cout<<"GCB ";
                      cout<<a[i]<<endl;
                      break;
                      }
        }
    }
return 0;
}

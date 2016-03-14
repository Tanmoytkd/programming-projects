#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    vector<string> names;
    names.push_back("RAKIBUL");
    names.push_back("ANINDYA");
    names.push_back("MOSHIUR");
    names.push_back("SHIPLU");
    names.push_back("KABIR");
    names.push_back("SUNNY");
    names.push_back("OBAIDA");
    names.push_back("WASI");
    int occur[8]={0};
    int nsize = names.size();
    int sum[nsize], multi[nsize], counter[nsize];
    for(int i=0; i<nsize; i++) {
        int len=names[i].length();
        sum[i]=0;
        multi[i]=1;
        counter[i]=0;
        for(int j=0; j<len; j++) {
            int val=(names[i])[j]-'A'+1;
            sum[i]+=val;
            multi[i]*=val;
            counter[i]++;
        }
    }

    string origin="OBIDAIBKRRKAULHISPSADIYANNOHEISAWHIAIRAKIBULSMFBINTRNOUTOYZIFAHLEBSYNUNEEMOTIONAL";
    int lenstr=origin.length();

    for(int k=0; k+9<=lenstr; k+=9) {
        for(int l=k; l<k+9; l++) {
            int isum=0, imulti=1, icounter=0;
            for(int m=l; m<k+9; m++) {
                icounter++;
                int val=origin[m]-'A'+1;
                isum+=val;
                imulti*=val;

                for(int i=0; i<nsize; i++) {
                    if(icounter==counter[i] && imulti==multi[i] && isum==sum[i]) {
                        occur[i]++;
                        if(occur[i]==2) cout << names[i] << endl;
                    }
                }
            }
        }
    }

    char str[lenstr+1];
    str[lenstr]='\0';
    int pos=0, newpos;
    while(pos<lenstr) {
        int row, col;
        row=pos/9;
        col=pos%9;
        newpos=9*col+row;
        str[pos]=origin[newpos];
        pos++;
    }
    origin = str;

    for(int k=0; k+9<=lenstr; k+=9) {
        for(int l=k; l<k+9; l++) {
            int isum=0, imulti=1, icounter=0;
            for(int m=l; m<k+9; m++) {
                icounter++;
                int val=origin[m]-'A'+1;
                isum+=val;
                imulti*=val;

                for(int i=0; i<nsize; i++) {
                    if(icounter==counter[i] && imulti==multi[i] && isum==sum[i]) {
                        occur[i]++;
                        if(occur[i]==2) cout << names[i] << endl;
                    }
                }
            }
        }
    }
    return 0;
}

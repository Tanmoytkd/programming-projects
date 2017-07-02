#include <bits/stdc++.h>
using namespace std;

int kmp(char text[], char pattern[], int l1=-1, int l2=-1, char delim=7) {
    if(l1==-1) {
        l1=strlen(text);
    }
    if(l2==-1) {
        l2=strlen(pattern);
    }

    int finlen=l1+l2+2;
    //finlen is final length of string after adding text and pattern
    char str[finlen];
    int suff[finlen];
    strcpy(str, pattern);
    str[l2]=delim;
    str[l2+1]=0;
    strcat(str, text);


    int i=1, j=0, res=-1;
    while(i<finlen) {
        if(str[i]==str[j]) {
            suff[i]=j+1;
            if(suff[i]==l2 && res==-1) {
                res=i-l2+1 -(l2+1);
            }
            /*subtract l2 and add 1 to go to the beginning of word
            then subtract (l2+1) to get rid of the prefix pattern*/

            i++;
            j++;
        }
        else if(j!=0) {
            j=suff[j-1];
        }
        else {
            suff[i]=0;
            i++;
        }
    }

    return res;
}

int main() {
    char s1[1000], s2[1000];
    scanf("%s%s", s1, s2);
    cout << s1 << " " << s2 << endl;

    int finpos=kmp(s1, s2);
    if(finpos==-1) cout << "Not found" << endl;
    else cout << "found at position " << finpos << endl;
    return 0;
}

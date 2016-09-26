#include <bits/stdc++.h>
#define sc scanf
#define pf printf
#define pb push_back

using namespace std;

long long convert(char *str, int base) {
    return strtoll(str, NULL, base);
}

int main() {
    char num1[100], num2[100];
    while(sc("%s %s", num1, num2)==2) {
        int base1=2, base2=2, len1=strlen(num1), len2=strlen(num2);

        for(int i=0; i<len1; i++)
            if(!isdigit(num1[i])) base1=max(base1, num1[i]-'A'+11);
            else base1=max(base1, num1[i]-'0'+1);
        for(int i=0; i<len2; i++)
            if(!isdigit(num2[i])) base2=max(base2, num2[i]-'A'+11);
            else base2=max(base2, num2[i]-'0'+1);

        long long n1, n2;
        for(; base1<37 && base2<37; ) {
            n1=convert(num1, base1);
            n2=convert(num2, base2);

            if(n1<n2) base1++;
            else if(n2<n1) base2++;
            else break;
        }
        if(base1==37 || base2==37) pf("%s is not equal to %s in any base 2..36\n", num1, num2);
        else pf("%s (base %d) = %s (base %d)\n", num1, base1, num2, base2);
    }

    return 0;
}

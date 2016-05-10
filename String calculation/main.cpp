#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string trim(string &val, int n=0) {
    int i=n, len=val.length()-1;
    for(; i<len-1; i++) if(val[i]!='0') break;
    return val.substr(i);
}

class bigInt {
    private:
    string value;
    char sign;

    public:
    bigInt() {
    }

    bigInt(char s, string &val) {
        sign=s;
        value=trim(val);
    }

    bigInt(string &val) {
        if(val[0]=='-') {
            sign='-';
            value=trim(val, 1);
        }
        else if(val[0]=='+') {
            sign='+';
            value=trim(val, 1);
        }
        else {
            sign='+';
            value=trim(val);
        }
    }

    template<typename T>
    bigInt(T x) {
        if(x<0) {
            sign='-';
            x=0-x;
        }
        else sign='+';

        string val="";
        while(x) {
            val+= ('0' + x%10);
            x/=10;
        }
        reverse(val.begin(), val.end());
        value=val;
    }

    string strval() {
        return value;
    }

    char strsign() {
        return sign;
    }

    template<typename T>
    void operator= (T x) {
        if(x<0) {
            sign='-';
            x=0-x;
        }
        else sign='+';

        string val="";
        while(x) {
            val+= '0' + x%10;
            x/=10;
        }
        reverse(val.begin(), val.end());
        value=val;
    }

    void operator= (string &val) {
        if(val[0]=='-') {
            sign='-';
            value=trim(val, 1);
        }
        else if(val[0]=='+') {
            sign='+';
            value=trim(val, 1);
        }
        else {
            sign='+';
            value=trim(val);
        }
    }

    void operator= (bigInt x) {
        value = x.strval();
        sign = x.strsign();
    }

    string add (string large, string small) {
        string sum="";
        int carry=0;

        if(large.length()<small.length()) small.swap(large);

        int i=large.length()-1, j=small.length()-1, digsum;

        for(; j>=0; i--, j--) {
            digsum=large[i]-'0'+small[j]-'0'+carry;
            sum+='0'+ digsum%10;
            carry=digsum/10;
        }
        for(; i>=0; i--) {
            digsum=large[i]-'0'+carry;
            sum+='0'+ digsum%10;
            carry=digsum/10;
        }
        if(carry==1) sum+='1';

        reverse(sum.begin(), sum.end());
        return sum;
    }

    string difference(string large, string small) {
        string diff="";

        if(large.length()<small.length()) large.swap(small);

        reverse(small.begin(), small.end());
        reverse(large.begin(), large.end());

        int i=0, slen=small.length(), llen=large.length();

        for(; i<slen; i++) {
            if(large[i]>=small[i]) diff+= '0'+ large[i]-small[i];
            else {
                diff += '0'+10+large[i]-small[i];
                large[i+1]--;
            }
        }

        for(; i<llen; i++) {
            if(large[i]>='0') diff+=large[i];
            else {
                diff+=large[i]+10;
                large[i+1]--;
            }
        }

        reverse(diff.begin(), diff.end());
        unsigned int j=0;
        for(; j<diff.length()-1; j++) {
            if(diff[j]!='0') break;
        }
        diff = diff.substr(j);
        return diff;
    }

    bigInt operator- (bigInt num) {
        string numval=num.strval();
        if(sign==num.strsign()) {
            if(value>numval) {
                string diff=difference(value, numval);
                return bigInt (sign, diff);
            }
        }
    }

    bigInt operator+ (bigInt num) {

        string sum, numval=num.strval();
        char newsign;
        if(sign==num.strsign()) {
            sum = add(value, numval);
            return bigInt(sign, sum);
        }
        else {
            sum = difference(value, numval);
            int compare = value.compare(numval);
            if(compare>0) newsign=sign;
            else if(compare<0) newsign=num.strsign();
            else newsign='+';

            return bigInt(newsign, sum);
        }
    }

    template<class T>
    bigInt operator+ (T x) {
        bigInt num(x);
        if(sign==num.strsign()) {
            string sum = add(value, num.strval());
            return bigInt(sign, sum);
        }
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bigInt x(s1), y(s2), difference, sum;
    sum=x+y;
    //difference=x-y;
    //if(sum.strsign()=='-')
    cout << sum.strsign();
    cout << sum.strval() << endl;
    //cout << difference.strval() << endl;
    return 0;
}

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
    string value="";
    char sign='+';

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
/*
    bigInt(int x) {
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

    bigInt(unsigned int x) {
        sign='+';

        string val="";
        while(x) {
            val+= '0' + x%10;
            x/=10;
        }
        reverse(val.begin(), val.end());
        value=val;
    }

    bigInt(long long x) {
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

    bigInt(unsigned long long x) {
        string val="";
        while(x) {
            val+= '0' + x%10;
            x/=10;
        }
        reverse(val.begin(), val.end());
        value=val;
        sign='+';
    }
*/
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

    /*
    void operator= (int x) {
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

    void operator= (unsigned int x) {
        sign='+';

        string val="";
        while(x) {
            val+= '0' + x%10;
            x/=10;
        }
        reverse(val.begin(), val.end());
        value=val;
    }

    void operator= (long long x) {
        string val="";
        while(x) {
            val+= '0' + x%10;
            x/=10;
        }
        reverse(val.begin(), val.end());
        value=val;
        if(x<0) sign='-';
        else sign='+';
    }

    void operator= (unsigned long long x) {
        string val="";
        while(x) {
            val+= '0' + x%10;
            x/=10;
        }
        reverse(val.begin(), val.end());
        value=val;
        sign='+';
    }
    */

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

    bigInt operator+ (bigInt num) {
        if(sign==num.strsign()) {
            string sum = add(value, num.strval());
            return bigInt(sign, sum);
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
    cin >> s1;
    bigInt x(s1), y(1), sum;
    sum=x+y;
    cout << sum.strval() << endl;
    return 0;
}

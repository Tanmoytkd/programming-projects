#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

    string trim(string &val, int n=0) {
        int i=n, len=val.length()-1;
        for(; i<len-1; i++) if(val[i]!='0') break;
        return val.substr(i);
    }

    char toogle(char ch) {
        if(ch=='+') return '-';
        else if(ch=='-') return '+';
        else return ch;
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

        int compare=large.compare(small);
        if(compare<1) large.swap(small);

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

        int compare=large.compare(small);
        if(compare<1) large.swap(small);

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

    string multiply(string val, string numval) {
        string result="";
        int l1=val.length(), l2=numval.length(), len=l1+l2;
        for(int i=0; i<len; i++) result+='0';

        reverse(val.begin(), val.end());
        reverse(numval.begin(), numval.end());

        int n1, n2, product, k=0, carry=0, pos=0;
        for(int i=0; i<l1; i++) {
            k=i;
            n1=val[i]-'0';
            for(int j=0; j<l2; j++, k++) {
                n2=numval[j]-'0';
                product=n1*n2+carry+(result[k]-'0');
                result[k]=product%10+'0';
                carry=product/10;
            }
            for(; carry>0; k++) {
                product=(result[k]-'0')+carry;
                result[k]=product%10+'0';
                carry=product/10;
            }
        }
        reverse(result.begin(), result.end());
        for(pos=0; pos<len-1; pos++) if(result[pos]!='0') break;
        result=result.substr(pos);
        return result;
    }

    string divide(string large, const string small) {
        if(large.compare(small)<0) {
            string zero="0";
            return zero;
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
        bigInt num1(sign, value);
        bigInt num2(x);
        return num1+num2;
    }

    bigInt operator- (bigInt num) {
        string numval=num.strval(), diff;

        if(sign==num.strsign()) {
            diff=difference(value, numval);
            int compare = value.compare(num.strval());
            if(compare>0) {
                return bigInt (sign, diff);
            }
            else if(compare<0) {
                return bigInt(toogle(sign), diff);
            }
            else return bigInt('+', diff);
        }
        else {
            diff=add(value, numval);
            return bigInt(sign, diff);
        }
    }

    template<class T>
    bigInt operator- (T x) {
        bigInt num1(sign, value);
        bigInt num2(x);
        return num1-num2;
    }

    bigInt operator* (bigInt num) {
        string res=multiply(value, num.strval());
        if(res=="0") return bigInt('+', res);
        if(sign==num.strsign()) return bigInt('+', res);
        else return bigInt('-', res);
    }

    template<class T>
    bigInt operator* (T x) {
        bigInt num1(sign, value);
        bigInt num2(x);
        return num1*num2;
    }


};

int main()
{
    string s1;
    int s2;
    cin >> s1 >> s2;
    bigInt x(s1), y(s2), difference, sum, product, result;
    sum=x+y;
    difference=x-y;
    product=x*y;
    //result=y-(x-y);

    if(sum.strsign()=='-') cout << sum.strsign();
    cout << sum.strval() << endl;

    if(difference.strsign()=='-') cout << difference.strsign();
    cout << difference.strval() << endl;

    if(product.strsign()=='-') cout << product.strsign();
    cout << product.strval() << endl;

    //if(result.strsign()=='-') cout << result.strsign();
    //cout << result.strval() << endl;
    return 0;
}

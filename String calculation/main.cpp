#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class bigInt {
    private:
    string value;
    char sign;

    public:
    string trim(string &val, int n=0) {
        int i=n, len=val.length()-1;
        for(; i<len-1; i++) if(val[i]!='0') break;
        val=val.substr(i);
        return val;
    }

    char toogle(char ch) {
        if(ch=='+') return '-';
        else if(ch=='-') return '+';
        else return ch;
    }

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
        return trim(sum);
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
        return trim(diff);
    }

    string multiply(string val, string numval) {
        string result="";
        int l1=val.length(), l2=numval.length(), len=l1+l2;
        for(int i=0; i<len; i++) result+='0';

        reverse(val.begin(), val.end());
        reverse(numval.begin(), numval.end());

        int n1, n2, product, k=0, carry=0;
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
        return trim(result);
    }

    string divide(string large, const string small) {
        if(large.compare(small)<0) {
            string zero="0";
            return zero;
        }

        string result="", newlarge="";
        int i=0, largelen=large.length();

        while(newlarge.length()<small.length() && i<largelen) {
            newlarge+=large[i];
            i++;
        }

        int num=0;
        while(i<largelen) {
            while(newlarge.compare(small)>=0) {
                newlarge=difference(newlarge, small);
                num++;
            }
            result+='0'+num;
            num=0;
            if(i<largelen) {
                newlarge+=large[i];
                i++;
            }
            while(newlarge.length()<small.length() && i<largelen) {
                newlarge+=large[i];
                i++;
            }
        }
        while(newlarge.compare(small)>=0) {
            newlarge=difference(newlarge, small);
            num++;
        }
        result+='0'+num;
        num=0;
        return trim(result);
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

    bigInt operator/ (bigInt num) {
        string res=divide(value, num.strval());
        if(res=="0") return bigInt('+', res);
        if(sign==num.strsign()) return bigInt('+', res);
        else return bigInt('-', res);
    }

    template<class T>
    bigInt operator/ (T x) {
        bigInt num1(sign, value);
        bigInt num2(x);
        return num1/num2;
    }
};

int main()
{
    string s1;
    int y;
    cin >> s1 >> y;
    bigInt x(s1), difference, sum, product, div, result;
    sum=x+y;
    difference=x-y;
    product=x*y;
    div=x/y;
    //result=y-(x-y);

    cout << "x" << endl;
    if(x.strsign()=='-') cout << x.strsign();
    cout << x.strval() << endl << endl;

    /*cout << "y" << endl;
    if(y.strsign()=='-') cout << y.strsign();
    cout << y.strval() << endl << endl;*/

    if(sum.strsign()=='-') cout << sum.strsign();
    cout << sum.strval() << endl;

    if(difference.strsign()=='-') cout << difference.strsign();
    cout << difference.strval() << endl;

    if(product.strsign()=='-') cout << product.strsign();
    cout << product.strval() << endl;

    if(div.strsign()=='-') cout << div.strsign();
    cout << div.strval() << endl;

    //if(result.strsign()=='-') cout << result.strsign();
    //cout << result.strval() << endl;
    return 0;
}

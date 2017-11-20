#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%I64d",&a)
#define sf2ll(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i, x) for(int i = 1; i<=x ; i++)

using namespace std;
typedef long long int lint;
typedef double dbl;


class bigInt {
    private:
    string value;
    char sign;

    public:
    bigInt purify() {
        if(sign=='-' && trim(value)=="0") sign='+';
        return *this;
    }

    bigInt reverse_() {
        purify();
        string val=value;
        reverse(val.begin(), val.end());
        trim(val);
        return bigInt(sign, val);
    }

    bigInt _reverse() {
        purify();
        reverse(value.begin(), value.end());
        trim(value);
        return *this;
    }

    int strcompare(const string &x, const string &y) {
        if(x.length()>y.length()) return 1;
        else if(x.length()<y.length()) return -1;
        else return x.compare(y);
    }

    string trim(string &val, int n=0) {
        int i=n, len=val.length()-1;
        for(; i<len; i++) if(val[i]!='0') break;
        val=val.substr(i);
        return val;
    }

    char toogle(char ch) {
        if(ch=='+') return '-';
        else if(ch=='-') return '+';
        else return ch;
    }

    bigInt() {
        sign='+';
        value="0";
        purify();
    }

    bigInt(char s, string &val) {
        sign=s;
        value=trim(val);
        purify();
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
        purify();
    }

    bigInt(const char * str) {
        string val(str);
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
        purify();
    }

    template<typename T>
    bigInt(T x) {
        if(x<0) {
            sign='-';
            x=0-x;
        }
        else sign='+';

        string val="";
        do {
            val+= ('0' + x%10);
            x/=10;
        } while(x);
        reverse(val.begin(), val.end());
        value=val;
        purify();
    }

    string strval() {
        return value;
    }

    const char * strval() const{
        return value.c_str();
    }

    string val() {
        string res="";
        if(sign=='-') res="-";
        return res+value;
    }

    const char * val() const{
        string res="";
        if(sign=='-') res="-";
        return (res+value).c_str();
    }

    char strsign() {
        return sign;
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
        purify();
    }

    void operator= (bigInt x) {
        value = x.strval();
        sign = x.strsign();
        purify();
    }

    template<typename T>
    void operator= (T x) {
        if(x<0) {
            sign='-';
            x=0-x;
        }
        else sign='+';

        string val="";
        do {
            val+= '0' + x%10;
            x/=10;
        } while(x);
        reverse(val.begin(), val.end());
        value=val;
        purify();
    }


    string add (string large, string small) {
        string sum="";
        int carry=0;

        if(strcompare(large, small)<0) large.swap(small);

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

        if(strcompare(large, small)<0) large.swap(small);

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

    string divide(const string large, const string small, string &newlarge) {
        if(strcompare(large,small)<0) {
            string zero="0";
            newlarge=large;
            return zero;
        }

        string result="";
        int i=0, largelen=large.length();

        while(newlarge.length()<small.length() && i<largelen) {
            newlarge+=large[i];
            trim(newlarge);
            i++;
        }

        int num=0;
        while(i<largelen) {
            while(strcompare(newlarge,small)>=0) {
                newlarge=difference(newlarge, small);
                num++;
            }
            result+='0'+num;
            num=0;
            if(i<largelen) {
                newlarge+=large[i];
                i++;
            }
            trim(newlarge);
        }
        while(strcompare(newlarge,small)>=0) {
            newlarge=difference(newlarge, small);
            num++;
        }
        result+='0'+num;
        num=0;
        return trim(result);
    }

    string divide(const string large, const string small) {
        string blank="";
        return divide(large, small, blank);
    }

    string mod(const string large, const string small) {
        string m="";
        divide(large, small, m);
        return trim(m);
    }

    bigInt operator+ (bigInt num) {
        string sum, numval=num.strval();
        char newsign;
        if(sign==num.strsign()) {
            sum = add(value, numval);
            return bigInt(sign, sum).purify();
        }
        else {
            sum = difference(value, numval);
            int compare = strcompare(value, numval);
            if(compare>0) newsign=sign;
            else if(compare<0) newsign=num.strsign();
            else newsign='+';

            return bigInt(newsign, sum).purify();
        }
    }

    template<class T>
    bigInt operator+ (T x) {
        return *this+bigInt(x);
    }

    bigInt operator+= (bigInt x) {
        bigInt c= *this+x;
        sign=c.strsign();
        value=c.strval();
        return *this;
    }

    template<class T>
    bigInt operator+= (T x) {
        return *this+= bigInt(x);
    }

    bigInt operator- (bigInt num) {
        string numval=num.strval(), diff;

        if(sign==num.strsign()) {
            diff=difference(value, numval);
            int compare = strcompare(value, numval);
            if(compare>0) {
                return bigInt (sign, diff).purify();
            }
            else if(compare<0) {
                return bigInt(toogle(sign), diff).purify();
            }
            else return bigInt('+', diff);
        }
        else {
            diff=add(value, numval);
            return bigInt(sign, diff).purify();
        }
    }

    template<class T>
    bigInt operator- (T x) {
        return *this-bigInt(x);
    }

    bigInt operator-= (bigInt x) {
        bigInt c= *this-x;
        sign=c.strsign();
        value=c.strval();
        return *this;
    }

    template<class T>
    bigInt operator-= (T x) {
        return *this-= bigInt(x);
    }

    bigInt operator* (bigInt num) {
        string res=multiply(value, num.strval());
        if(res=="0") return bigInt('+', res);
        if(sign==num.strsign()) return bigInt('+', res);
        else return bigInt('-', res).purify();
    }

    template<class T>
    bigInt operator* (T x) {
        return *this*bigInt(x);
    }

    bigInt operator*= (bigInt x) {
        bigInt c= *this*x;
        sign=c.strsign();
        value=c.strval();
        return *this;
    }

    template<class T>
    bigInt operator*= (T x) {
        return *this*= bigInt(x);
    }

    bigInt operator/ (bigInt num) {
        if(num==0) throw -1;
        string res=divide(value, num.strval());
        if(res=="0") return bigInt('+', res);
        if(sign==num.strsign()) return bigInt('+', res);
        else return bigInt('-', res).purify();
    }

    template<class T>
    bigInt operator/ (T x) {
        return *this/bigInt(x);
    }

    bigInt operator/= (bigInt x) {
        bigInt c= *this/x;
        sign=c.strsign();
        value=c.strval();
        return *this;
    }

    template<class T>
    bigInt operator/= (T x) {
        return *this/= bigInt(x);
    }

    bigInt operator% (bigInt num) {
        string m=mod(value, num.strval());
        return bigInt(sign, m).purify();
    }

    template<class T>
    bigInt operator% (T x) {
        return *this%bigInt(x);
    }

    bigInt operator%= (bigInt x) {
        bigInt c= *this%x;
        sign=c.strsign();
        value=c.strval();
        return *this;
    }

    template<class T>
    bigInt operator%= (T x) {
        return *this%= bigInt(x);
    }

    bool operator== (bigInt num) {
        return sign==num.strsign() && value==num.strval();
    }

    template<class T>
    bool operator== (T x) {
        return *this==bigInt(x);
    }

    bool operator!= (bigInt num) {
        return sign!=num.strsign() || value!=num.strval();
    }

    template<class T>
    bool operator!= (T x) {
        return *this!=bigInt(x);
    }

    bool operator> (bigInt num) {
        if(sign=='+' && num.strsign()=='-') return true;
        else if(sign=='-' && num.strsign()=='+') return false;
        else if(sign=='+') return strcompare(value, num.strval())>0;
        else return strcompare(value, num.strval())<0;
    }

    template<class T>
    bool operator> (T x) {
        return *this>bigInt(x);
    }

    bool operator< (bigInt num) {
        if(sign=='+' && num.strsign()=='-') return false;
        else if(sign=='-' && num.strsign()=='+') return true;
        else if(sign=='+') return strcompare(value, num.strval())<0;
        else return strcompare(value, num.strval())>0;
    }

    template<class T>
    bool operator< (T x) {
        return *this<bigInt(x);
    }

    template<class T>
    bool operator>= (T x) {
        return *this==x || *this>x;
    }

    template<class T>
    bool operator<= (T x) {
        return *this==x || *this<x;
    }

    bigInt& operator++ () {
        *this=*this+1;
        return *this;
    }

    bigInt operator++(int) {
        bigInt temp=*this;
        operator++();
        return temp;
    }

    bigInt& operator-- () {
        *this=*this-1;
        return *this;
    }

    bigInt operator--(int) {
        bigInt temp=*this;
        operator--();
        return temp;
    }

    operator int() const {return atoi(val());}
    operator long() const {return atol(val());}
    operator long long() const {return atoll(val());}
    friend istream& operator>> (istream&, bigInt&);
    friend ostream& operator<< (ostream&, bigInt&);

    template<class T>
    friend bigInt operator+ (T, bigInt);

    template<class T>
    friend bigInt operator- (T, bigInt);

    template<class T>
    friend bigInt operator* (T, bigInt);

    template<class T>
    friend bigInt operator/ (T, bigInt);

    template<class T>
    friend bigInt operator% (T, bigInt);
};

template<class T>
bigInt operator+ (T x, bigInt y) {
    return bigInt(x).operator+(y);
}

template<class T>
bigInt operator- (T x, bigInt y) {
    return bigInt(x).operator-(y);
}

template<class T>
bigInt operator* (T x, bigInt y) {
    return bigInt(x).operator*(y);
}

template<class T>
bigInt operator/ (T x, bigInt y) {
    return bigInt(x).operator/(y);
}

template<class T>
bigInt operator% (T x, bigInt y) {
    return bigInt(x).operator%(y);
}

istream& operator>> (istream& in, bigInt& n) {
    string s;
    in >> s;
    n = bigInt(s);
}

ostream& operator<< (ostream& out, bigInt& n) {
    if(n.sign=='-') out << n.sign;
    out<< n.value;
}

typedef bigInt bint;

bigInt root(bigInt & num, bigInt start, bigInt fin) {
    if(start>fin) return 1;
    bint mid=(start+fin)/2;
    bint n=mid*mid;
    if(n == num) return mid;
    if(n<num) return root(num, mid+1, fin);
    if(n>num) return root(num, start, mid-1);
}

bigInt root(bigInt & num) {
    bint fin=1;
    while(fin*fin < num) {
        fin*=10;
    }
    return root(num, 0, fin);
}

int main()
{
    int t, tst = 1;

    sf1(t);

    while(t--) {
        string s;
        cin >> s;

        bigInt num=s;

        bint res=root(num);

        cout << res << endl;
        if(t) puts("");
    }
    return 0;
}

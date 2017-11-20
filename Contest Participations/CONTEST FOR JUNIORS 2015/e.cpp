/*
ID: tanmoyk2
PROG:
LANG: C++11
*/

#include <bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define FOR(I, N) for(int I=0; I<N; I++)
#define FOR1(I, N) for(int I=1; I<=N; I++)

using namespace std;

#define mod 1000000007

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}

vector<string>x;
vector<string>post;
stack<string> oper;
int pos;
int invalid=0;

bool comp(const string& x, const string& y) {
    if(x.length()==y.length()) return x<y;
    return x.length()<y.length();
}

struct node {
    string s;
    node *left, *right;

    node() {
        s="";
        left=NULL;
        right=NULL;
    }
};

int isoperator(const string& s) {
    return s=="+" || s=="-" || s=="*" || s=="/";
}

int isoperator(char ch) {
    return ch=='+' || ch=='-' || ch=='*' || ch=='/';
}

void go(node * p) {
    if(!(isoperator(post[pos]))) {
        p->s=post[pos];
        pos--;
        return;
    }

    p->s=post[pos];
    pos--;
    p->left=new node;
    p->right=new node;
    node * left=p->left, * right=p->right;
    go(right);
    go(left);

    p->s = left->s + " " + right->s + " " + p->s;
    //cout << p->s << " node " << endl;;
    x.pb(p->s);
    //cout << x.back() << endl;
    //cout << x.size() << endl;
}


int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    char str[1111];
    while(gets(str)!=NULL) {
        invalid=0;
        int l=strlen(str);

        string s="";
        vector<string>v;

        FOR(i, l+1) {
            if(i==l) break;
            if(str[i]==' ') continue;
            else if(str[i]=='(') v.pb(string("("));
            else if(str[i]==')') v.pb(string(")"));
            else if(isoperator(str[i])) v.pb(string("")+str[i]);
            else /*if(i!=l)*/ {
                int j=i;
                while(j<l && isdigit(str[j])) j++;
                if(i!=j) {
                    v.pb(string(str+i, str+j));
                    i=j-1;
                }
            }
            //cout << v.back() << endl;
        }

        FOR1(i, v.size()-1) {
            if(isoperator(v[i]) && isoperator(v[i-1])) {
                invalid=1;
                break;
            }
        }
        if(v[0]==")" || isoperator(v[0]) || isoperator(v[v.size()-1]) || v[v.size()-1]=="(") invalid=1;
        else {
            int state=0;
            FOR(i, v.size()-2) {
                if(v[i]=="(") {
                    state++;
                    if(isoperator(v[i+1]) || v[i+1]==")") {
                        invalid=1;
                        break;
                    }
                }
                else if(v[i]==")") {
                    state--;
                    if(!(isoperator(v[i+1]) || v[i+1]==")")) {
                        invalid=1;
                        break;
                    }
                }
                else if(isoperator(v[i])) {
                    if(v[i+1]==")" || isoperator(v[i+1])) {
                        invalid=1;
                        break;
                    }
                }
                else {
                    if(!( v[i+1]==")" || isoperator(v[i+1]) ) ) {
                        invalid=1;
                        break;
                    }
                }

                if(state<0) {
                    invalid=1;
                    break;
                }
            }
            if(state>1) {
                invalid=1;
            }
            else if(state==1 && v[v.size()-1]!=")") {
                invalid=1;
            }
        }

        if(invalid) {
            cout << "ERROR" << endl;
            continue;
        }

        //cout << "TKD " << endl;
         vector<string> temp1;
         post=temp1;
         while(!oper.empty()) oper.pop();

         FOR(i, v.size()) {
            if(v[i]=="(") {
                oper.push(v[i]);
            }
            else if(v[i]==")") {
                while(!oper.empty() && oper.top()!="(") {
                    post.pb(oper.top());
                    oper.pop();
                }
                if(!oper.empty()) oper.pop();
            }
            else if(!isoperator(v[i])) {
                post.pb(v[i]);
            }
            else {
                while(!oper.empty() && !(oper.top()=="(") && !((v[i]=="*" || v[i]=="/") && (oper.top()=="+" || oper.top()=="-"))) {
                    string temp=oper.top();
                    oper.pop();
                    post.pb(temp);
                }
                oper.push(v[i]);
            }
         }

         while(!oper.empty()) {
            string temp=oper.top();
            oper.pop();
            post.pb(temp);
         }

         FOR(i, post.size()) {
            if(post[i]==")" || post[i]=="(") {
                invalid=1;
                break;
            }
         }

         if(invalid) {
            cout << "ERROR" << endl;
            continue;
         }

         vector<string>temp;
         x=temp;

//         FOR(i, post.size()) {
//            cout << post[i] << " ";
//         }
//         cout << endl;


         pos=post.size()-1;

         node * p = new node;

         go(p);


//        for(int pos=post.size()-1; pos>=0; pos--) {
//            if(isoperator(post[pos])) {
//                string res="";
//                int level=1;
//                int sp=pos;
//                for(; sp>=0; sp--) {
//                    if(isoperator(post[sp])) level++;
//                    else level--;
//
//                    if(level==0) break;
//                }
//                if(sp<0) sp++;
//                for(; sp<pos; sp++) res+= post[sp]+ " ";
//                res+=post[sp];
//
//                x.pb(res);
//            }
//        }

        sort(x.begin(), x.end(), comp);

        for(int i=x.size()-1; i>=1; i--) {
            //cout << x[i] << endl;
            if(x[i]==x[i-1]) {
                cout << x[i] << endl;
                break;
            }
        }

         //a+b*c+d/c
    }
    return 0;
}

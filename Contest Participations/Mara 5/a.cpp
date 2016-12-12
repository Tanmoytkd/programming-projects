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
#define pdd pair<double, double>
using namespace std;
#define fs first
#define sc second
#define mod 1000000007

long long bigmod(long long a, long long power, long long m=mod) {
    if(power==0) return 1%m;
    if(power&1) return (a * bigmod(a, power-1))%m;
    long long r = bigmod(a, power/2);
    return (r*r)%m;
}

double dist(pdd a, pdd b) {
    return (a.fs-b.fs)*(a.fs-b.fs) + (a.sc-b.sc)*(a.sc-b.sc);
}

int main() {
    #ifdef TKD
    //freopen("i.txt", "r", stdin);
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif

    int v, m;
    while(sf2(v, m)==2 && v && m) {
        double maxdist=v*m*60;
        maxdist*=maxdist;

        double xs, ys;
        sf("%lf %lf", &xs, &ys);
        pdd src(xs, ys);

        double xt, yt;
        sf("%lf %lf", &xt, &yt);
        pdd trg(xt, yt);

        vector<pdd > pt;
        map<pdd, int> level;

        string line;
        getline(cin, line);
        while(getline(cin, line)) {
            if(line.length()==0) break;
            stringstream ss(line);

            double x, y;
            ss >> x >> y;
            pt.pb(pdd(x,y));
        }

        if(src==trg) {
            puts("Yes, visiting 0 other holes.");
            continue;
        }
        else if(dist(src, trg)<=maxdist) {
            puts("Yes, visiting 0 other holes.");
            continue;
        }

        pt.pb(trg);

//        cout << src.fs <<" " << src.sc << endl;
//        cout << trg.fs <<" " << trg.sc << endl;
//        FOR(i, pt.size()) cout << pt[i].fs << " " << pt[i].sc << endl;


        int visit[pt.size()];
        FOR(i, pt.size()) visit[i]=0;
        //memset(visit, 0, sizeof visit);
        int possible=0;
        queue <pdd > q;
        q.push(src);
        level[src]=1;

        while(!q.empty() && !possible) {
            pdd hole = q.front();
            int lev=level[hole];
            q.pop();

            FOR(i, pt.size()) {
                if(visit[i]) continue;
                if(dist(hole, pt[i])<=maxdist) {
                    visit[i]=1;
                    q.push(pt[i]);
                    level[pt[i]]=lev+1;
                    if(pt[i]==trg) {
                        level[trg]=lev-1;
                        possible=1;
                        break;
                    }
                }
            }
        }

        if(possible) pf("Yes, visiting %d other holes.\n", level[trg]);
        else puts("No.");
    }
    return 0;
}

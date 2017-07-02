#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Saleswoman {
public:
	int minMoves(vector <int>, vector <int>);
};

int Saleswoman::minMoves(vector <int> pos, vector <int> delta) {
    int len = pos.size();
    vector<int> dist(len);
    for(int i=0; i<len-1; i++) {
        dist[i]=pos[i+1]-pos[i];
    }
    int res = pos[0];
    int sum=0;
    for(int i=0; i<len-1; i++) {
        sum+=delta[i];
        if(sum<0) res+=3*dist[i];
        else res+=dist[i];
    }
    return res;
}

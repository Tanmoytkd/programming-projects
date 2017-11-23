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

class Permutiple {
public:
	string isPossible(int);
};

string Permutiple::isPossible(int x) {
	string s="";
	int temp=x;
	while(x>0) {
		s+=('0'+ x%10);
		x/=10;
	}
	x=temp;
	sort(s.begin(), s.end());
	do {
		int num=0;
		for(int i=0; i<s.size(); i++) {
			num*=10;
			num+=s[i]-'0';
		}
		if(num==x) continue;
		if(num%x==0) return "Possible";
	} while(next_permutation(s.begin(), s.end()));

	return "Impossible";
}


// int main() {
// 	Permutiple p;
// 	int num;
// 	cin >> num;
// 	cout << p.isPossible(num) << endl;
// }

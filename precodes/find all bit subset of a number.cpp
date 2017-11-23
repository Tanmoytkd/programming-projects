/*
This loop gives all the nonempty bit subsets of a specific number
Example: Suppose, we have a number x = 1101
The loop will generate the numbers 1101, 1100, 1001, 1000, 0101, 0100, 0001 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int superset = 0b1101;
	for(int i=superset; i; i=(i-1)&superset) {
		bitset<4> bb(i);
		cout << bb << endl;
	}
}

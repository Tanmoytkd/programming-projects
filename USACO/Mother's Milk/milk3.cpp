/*
ID: tanmoyk2
PROG: milk3
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int acap,bcap,ccap;


struct  pots
{
	int a, b, c;
	pots(int x, int y, int z): a(x), b(y), c(z) {}
};

int visit[22][22][22];
set<int> res;
queue<pots> q;

void mark(pots x) {
	visit[x.a][x.b][x.c]=1;
}

int marked(pots x) {
	return visit[x.a][x.b][x.c]==1;
}

pots transform(pots x, char from, char to) {
	if(from=='a' && to == 'b') {
		int cap=min(x.a, bcap-x.b);
		x.a-=cap;
		x.b+=cap;
		return x;
	}
	if(from=='b' && to == 'a') {
		int cap=min(x.b, acap-x.a);
		x.b-=cap;
		x.a+=cap;
		return x;
	}
	if(from=='b' && to == 'c') {
		int cap=min(x.b, ccap-x.c);
		x.b-=cap;
		x.c+=cap;
		return x;
	}
	if(from=='c' && to == 'b') {
		int cap=min(x.c, bcap-x.b);
		x.c-=cap;
		x.b+=cap;
		return x;
	}
	if(from=='c' && to == 'a') {
		int cap=min(x.c, acap-x.a);
		x.c-=cap;
		x.a+=cap;
		return x;
	}
	if(from=='a' && to == 'c') {
		int cap=min(x.a, ccap-x.c);
		x.a-=cap;
		x.c+=cap;
		return x;
	}
}

void bfs() {
	while(!q.empty()) {
		pots x=q.front();
		q.pop();

		if(x.a==0) res.insert(x.c);

		pots one=transform(x, 'a', 'b');
		pots two=transform(x, 'b', 'a');
		pots three=transform(x, 'b', 'c');
		pots four=transform(x, 'c', 'b');
		pots five=transform(x, 'c', 'a');
		pots six=transform(x, 'a', 'c');

		if(!marked(one)) {
			mark(one);
			q.push(one);
		}

		if(!marked(two)) {
			mark(two);
			q.push(two);
		}

		if(!marked(three)) {
			mark(three);
			q.push(three);
		}

		if(!marked(four)) {
			mark(four);
			q.push(four);
		}

		if(!marked(five)) {
			mark(five);
			q.push(five);
		}

		if(!marked(six)) {
			mark(six);
			q.push(six);
		}
	}
}

int main() {
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin >> acap >> bcap >> ccap;
	pots beg(0,0,ccap);
	q.push(beg);
	mark(beg);
	res.insert(ccap);
	bfs();

	set<int>::iterator it;
	for(it=res.begin(); it!=res.end(); it++) {
		if(it!=res.begin()) fout << " ";
		fout << *it;
	}
	fout << endl;

	return 0;
}
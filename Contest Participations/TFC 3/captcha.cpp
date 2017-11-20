#include <bits/stdc++.h>
using namespace std;

vector<int> v;
char op[5] = "+-=";
int a[4];


int check(int i, int j, int k) {
	v.clear();
	int ok = 0;
	int pre=a[0];
	if(i==0) pre+=a[1];
	else if(i==1) pre-=a[1];
	else {
		ok=1;
		v.push_back(pre);
		pre=a[1];
	}

	if(j==0) pre+=a[2];
	else if(j==1) pre-=a[2];
	else {
		ok=1, v.push_back(pre);
		pre=a[2];
	}

	if(k==0) pre+=a[3];
	else if(k==1) pre-=a[3];
	else {
		ok=1;
		v.push_back(pre);
		pre=a[3];
	}

	if(ok) v.push_back(pre);
	else return false;
	for(int i=1; i<v.size(); i++) {
		if(v[i]!=v[i-1]) return false;
	}
	return true;
}

int main() {
	int X;
	scanf("%d", &X);
	for(int cas=1; cas<=X; cas++) {
		for(int i=0; i<4; i++) {
			scanf("%d", &a[i]);
		}
		printf("Case #%d: ", cas);
		int flag=0;
		for(int i=0; i<3; i++) {
			for(int j=0; j<3; j++) {
				for(int k=0; k<3; k++) {
					if(check(i, j, k)) {
						printf("%d %c %d %c %d %c %d\n", a[0], op[i], a[1], op[j], a[2], op[k], a[3]);
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}

	}

}
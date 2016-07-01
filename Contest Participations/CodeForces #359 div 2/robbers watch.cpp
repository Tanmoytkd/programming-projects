#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

#define digi(x) floor(log(x)/log(7))+1

int hdig, mdig;
long long counter=0, h, m;
int check[7]={0, 0, 0, 0, 0, 0, 0};

void minute(long long pos, long long mnt) {
	if(pos==mdig+1) {
		if(mnt>=m) return;
		counter++;
		return;
	}

	mnt*=7;
	for(int i=0; i<7; i++) {
		if(!check[i]) {
			check[i]=1;
			mnt+=i;
			minute(pos+1, mnt);
			mnt-=i;
			check[i]=0;
		}
	}
}

void hour(long long pos, long long hrs) {
	if(pos==hdig+1) {
		if(hrs>=h) return;
		minute(1, 0);
		return;
	}

	hrs*=7;
	for(int i=0; i<7; i++) {
		if(!check[i]) {
			check[i]=1;
			hrs+=i;
			hour(pos+1, hrs);
			hrs-=i;
			check[i]=0;
		}
	}
}

int main() {
	cin >> h >> m;
	hdig= digi(h);
	mdig= digi(m);

	hour(1, 0);
	cout << counter << endl;
	return 0;
}

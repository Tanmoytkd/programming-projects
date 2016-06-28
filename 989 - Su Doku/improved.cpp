#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

set<int> row[9], col[9], box[9];
int n, rows, cols, boxes, b[9][9], found=0, nr, nc;

void rec(int r, int c) {
    int ibox=(r/n)*n+c/n;
//    cout << r << " " << c << " " << ibox;
	if(r==rows) {
		found=1;
		return;
	}
	if(b[r][c]) {
//        cout << "\t" << "already exists " << b[r][c] << endl;
		nc=c+1;
		nr=r+(nc==cols);
		nc=nc%cols;
		rec(nr, nc);
		return;
	}
//	cout << endl;


	for(int i=1; i<=rows; i++) {
		if(found) return;

		int exist = row[r].find(i)!=row[r].end() || col[c].find(i)!=col[c].end() || box[ibox].find(i)!=box[ibox].end();
		if(exist) continue;


//		cout << '\t';
//		for(set<int>::iterator it=row[r].begin(), ite=row[r].end(); it!=ite; it++)
//			cout << *it << " ";
//		cout << endl << '\t';
//		for(set<int>::iterator it=col[c].begin(), ite=col[c].end(); it!=ite; it++)
//			cout << *it << " ";
//		cout << endl << '\t';
//		for(set<int>::iterator it=box[ibox].begin(), ite=box[ibox].end(); it!=ite; it++)
//			cout << *it << " ";
//		cout << endl;
//		cout << "i " << i << endl;

		b[r][c]=i;
		row[r].insert(i);
		col[c].insert(i);
		box[ibox].insert(i);

		nc=c+1;
		nr=r+(nc==cols);
		nc=nc%cols;
		rec(nr, nc);

        if(!found) b[r][c]=0;
		row[r].erase(i);
		col[c].erase(i);
		box[ibox].erase(i);
	}
}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

	int first=1;
	while(sc("%d", &n)==1) {
		int blankrow, blankcol;
		found=0;
		rows=cols=boxes=n*n;

		for(int i=0; i<rows; i++) {
			row[i].clear();
			col[i].clear();
			box[i].clear();
		}

		bool noconflict=true;

		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++) {
				int ibox=(i/n)*n+j/n;
				cin >> b[i][j];
				if(b[i][j]) {
					noconflict&=row[i].insert(b[i][j]).second;
					noconflict&=col[j].insert(b[i][j]).second;
                    noconflict&=box[ibox].insert(b[i][j]).second;
				}
				else {
					blankrow=i;
					blankcol=j;
				}
			}
		}

//		cout << endl << endl;
//		for(int i=0; i<rows; i++) {
//				for(int j=0; j<cols; j++) {
//					cout << b[i][j] << " \n"[j==cols-1];
//				}
//		}
//		cout << endl << endl;

		if(noconflict) rec(0, 0);
//		cout << endl; //comment it

		if(!first) pf("\n");
		else first=0;

		if(!noconflict || b[blankrow][blankcol]==0) pf("NO SOLUTION\n");
		else {
			for(int i=0; i<rows; i++) {
				for(int j=0; j<cols; j++) {
					cout << b[i][j] << " \n"[j==cols-1];
				}
			}
		}

	}

	return 0;
}

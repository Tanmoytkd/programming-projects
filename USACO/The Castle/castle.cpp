/*input
ID: tanmoyk2
PROG: castle
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;
typedef pair<int, int> pii;

int data[55][55], visit[55][55], cmp[55][55], total[55][55];
int r, c, cnt;
int fx[4] = {-1, 0, 1, 0}, fy[4] = {0, -1, 0, 1};
vector<pii> v;

int exist(int flag, int dir) {
	if(flag&(1<<dir)) return 1;
	return 0;
}

void dfs(int row, int col) {
	//fout << row << " " << col << endl;
	v.push_back(pii(row,col));
	cnt++;
	visit[row][col]=1;

	int flag = data[row][col];
	for(int dir=0; dir<4; dir++) {
		if(exist(flag, dir)) continue;
		int newrow=row+fy[dir];
		int newcol=col+fx[dir];

		if(newrow<1 || newcol<1 || newrow>r || newcol>c) continue;
		if(visit[newrow][newcol]) continue;
		dfs(newrow, newcol);
	}
}



int main() {
	ifstream fin("castle.in");
	ofstream fout("castle.out");
    fin >> c >> r;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            fin >> data[i][j];
        }
    }

    int roomcount=0;
    int largest=0;
    int largetotal=0;
    int ix, iy, idir;

    int comp=0;
    for(int i=1; i<=r; i++) {
    	for(int j=1; j<=c; j++) {
    		if(!visit[i][j]) {
    			cnt=0;
    			roomcount++;
    			dfs(i,j);
    			while(!v.empty()) {
    				pii z=v.back();
    				v.pop_back();
    				cmp[z.first][z.second]=comp;
    				total[z.first][z.second]=cnt;
    			}
    			largest=max(largest, cnt);
    			comp++;
    		}
    	}
    }

    for(int j=c; j>0; j--) {
    	for(int i=1; i<=r; i++) {
    		int d=data[i][j];
    		for(int dir=2; dir>=1; dir--) {
    			if(exist(d, dir)) {
    				int x=j+fx[dir];
    				int y=i+fy[dir];
    				if(cmp[y][x]==cmp[i][j]) continue;
    				int sumtotal = total[i][j]+total[y][x];
    				if(sumtotal>=largetotal) {
    					largetotal=sumtotal;
    					iy=i;
    					ix=j;
    					idir=dir;
    				}
    			}
    		}
    	}
    }

    // for(int i=1; i<=r; i++) {
    // 	for(int j=1; j<=c; j++) {
    // 		fout << total[i][j] << " ";
    // 	}
    // 	fout << endl;
    // }


    fout << roomcount << endl;
    fout << largest << endl;
    fout << largetotal << endl;
    fout << iy << " " << ix << " ";
    if(idir==0) fout << "W" << endl;
    else if(idir==1) fout << "N" << endl;
    else if(idir==2) fout << "E" << endl;
    else if(idir==3) fout << "S" << endl;

    return 0;
}

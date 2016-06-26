#include <bits/stdc++.h>
#define pf printf
#define sc scanf
#define pb push_back
#define Pb pop_back
using namespace std;

char board[2][4][4];
int counter=0, dpos=0, vowel=0, conso=0;
int st[2][4][4];
vector<char> current;
set<string> data[2];

int isvowel(char ch) {
	return ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='Y';
}

void rec(int row, int col) {
    if(row<0 || row==4 || col<0 || col==4) return;
    if(st[dpos][row][col]) return;

    int check=isvowel(board[dpos][row][col]);

    if(vowel==2 && check) {
        return;
    }
    if(conso==2 && !check) {
        return;
    }

    st[dpos][row][col]=1;
    current.pb(board[dpos][row][col]);

    vowel+=check;
    conso+=!check;

    if(current.size()==4) {
        string s(current.begin(), current.end());
        data[dpos].insert(s);
    }
    else {
        for(int nrow=row-1; nrow<=row+1; nrow++) {
            for(int ncol=col-1; ncol<=col+1; ncol++) {
                if(nrow==row && ncol==col) continue;
                rec(nrow, ncol);
            }
        }
    }


    vowel-=check;
    conso-=!check;

    current.Pb();
    st[dpos][row][col]=0;
}

int input() {
    char ch;

    	for(int i=0; i<4; i++) {
	        for(int pos=0; pos<2; pos++) {
	        	for(int j=0; j<4; j++) {
		            sc("%c", &ch);
		            while(!isalpha(ch) && ch!='#') sc("%c", &ch);
		            board[pos][i][j]=ch;
		            if(ch=='#') return 0;
	        	}
	        }
	    }
    return 1;
}

int main() {
    #ifdef TKD
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int first=1;
	while(input()) {
        counter=0;
        for(int i=0; i<2; i++) data[i].clear();

        for(dpos=0; dpos<2; dpos++) {
        	for(int i=0; i<4; i++) {
        		for(int j=0; j<4; j++) {
        			rec(i, j);
        		}
        	}
        }

        if(!first) pf("\n");
        first=0;

        set<string>::iterator it1=data[0].begin(), it1e=data[0].end(), it2=data[1].begin(), it2e=data[1].end();
        while(it1!=it1e && it2!=it2e) {
            if(*it1==*it2) {
                counter++;
                cout << *it1 << endl;
                it1++;
                it2++;
            }
            else if(*it1<*it2) it1++;
            else it2++;
        }
        if(counter==0)
            pf("There are no common words for this pair of boggle boards.\n");
	}
	return 0;
}

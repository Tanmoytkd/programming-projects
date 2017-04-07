/*
ID: tanmoyk2
PROG: wormhole
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int N, x[19], Y[19];
int partner[19];
int right_hole[19];

bool cycle()
{
  for (int beg=1; beg<=N; beg++) {
    int pos = beg;
    for (int counter=1; counter<=N; counter++)
      pos = right_hole[partner[pos]];
    if (pos != 0) return true;
  }
  return false;
}

int solve()
{
  int i, total=0;
  for (i=1; i<=N; i++) {
    if (partner[i] != 0) continue;
    if (i > N) {
        if (cycle()) return 1;
        else return 0;
    }
    for (int j=i+1; j<=N; j++) {
        if (partner[j] == 0) {
            partner[i] = j;
            partner[j] = i;
            total += solve();
            partner[i] = partner[j] = 0;
        }
    }
    break;
  }

  if (i > N) {
        if (cycle()) return 1;
        else return 0;
  }
  return total;
}

int main(void)
{
  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");

  fin >> N;
  for (int i=1; i<=N; i++) fin >> x[i] >> Y[i];

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      if (x[j] > x[i] && Y[i] == Y[j]) {
        if (right_hole[i] == 0 || x[j]-x[i] < x[right_hole[i]]-x[i]) {
            right_hole[i] = j;
        }
      }
    }
  }

  fout << solve() << "\n";
  return 0;
}

#include<iostream>
#include<cstdio>
#include<cmath>
#define ERROR 1e-8
using namespace std;

int main(){
  int X, num, m, N;
  while( scanf( "%d%d", &X, &num ) != EOF && !(X == 0 && num == 0)){
    if( X == 1 && num == 1 ){
      printf( "0 1\n");
      continue;
    }

    m = 1;
    while( X != (int)(pow(pow(num,1.0/m)+1.0, m)+ERROR) ) m++;
    N = (int)(pow(num,1.0/m)+ERROR);
    if( N != 1 ) printf( "%d %d\n", (1-num)/(1-N), (X-num)*N+X );
    else printf( "%d %d\n", m, (X-num)*N+X );
  }
  return 0;
}

/*
ID: tanmoytkd
LANG: C++11
PROG: pprime
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

bool isPrime(int num){
    int mx = sqrt(num) + 1;
    for(int i = 2; i < mx; i++){
        if(num % i == 0) return false;
    }
    return true;
}

vector<int> palindromes;

int main(){
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");

    int a, b;
    fin >> a >> b;

    palindromes.pb(5);
    palindromes.pb(7);

    for(int d0 = 1; d0 < 10; d0 += 2){ //2-digit palindromes
        palindromes.pb(10 * d0 + d0);
    }

    for(int d0 = 0; d0 < 10; d0++){ //3-digit/4-digit palindromes
        for(int d1 = 1; d1 < 10; d1 += 2){
            palindromes.pb(100 * d1 + 10 * d0 + d1); //3 digit
            palindromes.pb(1000 * d1 + 100 * d0 + 10 * d0 + d1); //4 digit
        }
    }

    for(int d0 = 0; d0 < 10; d0++){ //5-digit/6-digit palindromes
        for(int d1 = 0; d1 < 10; d1++){
            for(int d2 = 1; d2 < 10; d2 += 2){
                palindromes.pb(10000 * d2 + 1000 * d1 + 100 * d0 + 10 * d1 + d2);
                palindromes.pb(100000 * d2 + 10000 * d1 + 1000 * d0 + 100 * d0 + 10 * d1 + d2);
            }
        }
    }

    for(int d0 = 0; d0 < 10; d0++){ //7-digit/8-digit palindromes
        for(int d1 = 0; d1 < 10; d1++){
            for(int d2 = 0; d2 < 10; d2++){
                for(int d3 = 1; d3 < 10; d3 += 2){
                    palindromes.pb(1000000 * d3 + 100000 * d2 + 10000 * d1 + 1000 * d0 + 100 * d1 + 10 * d2 + d3);
                    palindromes.pb(10000000 * d3 + 1000000 * d2 + 100000 * d1 + 10000 * d0 + 1000 * d0 + 100 * d1 + 10 * d2 + d3);
                }
            }
        }
    }

    sort(palindromes.begin(), palindromes.end());
    for(int i = 0; i < palindromes.size(); i++){
        if(a <= palindromes[i] && palindromes[i] <= b && isPrime(palindromes[i])) fout << palindromes[i] << endl;
    }
}

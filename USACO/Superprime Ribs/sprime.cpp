/*
ID: tanmoyk2
LANG: C++11
PROG: sprime
*/
#include <bits/stdc++.h>
using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

int n;
int starters[4] = {2, 3, 5, 7};
int body[4] = {1, 3, 7, 9};

bool isPrime(int num){
    int root = sqrt(num);
    for(int i = 2; i <=root; i++){
        if(num % i == 0) return false;
    }
    return true;
}

void permute(string seed){
    if(seed.length() == n){
        int perm = strtol(seed.c_str(), NULL, 10);
        for(int j = 0; j < n; j++){
            if(!isPrime(perm)) return;
            perm /= 10;
        }
        fout << seed << endl;
    }
    else{
        if(seed.length() == 0){
            for(int i = 0; i < 4; i++){
                string ending = "";
                ending += starters[i] + '0';
                permute(seed + ending);
            }
        }
        else{
             for(int i = 0; i < 4; i++){
                string ending = "";
                ending += body[i] + '0';
                permute(seed + ending);
            }
        }
    }
}

int main(){

    fin >> n;

    permute("");
    return 0;
}

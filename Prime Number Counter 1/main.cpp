#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int primecount=0;
        for(int i=0; i<n; i++) {
            primecount += checkprime(i);
        }
        return primecount;
    }
    int checkprime(int num) {
        switch(num) {
            case 0: return 0;
            case 1: return 0;
            case 2: return 1;
            default: return check(num);
        }
    }
    int check(int num) {
        int result;
        for(int i=num/2; i>1; i--) {
            if(num%i==0) result=0;
        }
        return result;
    }
};

int main()
{
    int n;
    cout << "Please enter a number: ";
    cin >> n;
    Solution obj;
    cout << "The number of primes numbers before " << n << " is " <<obj.countPrimes(n);
    return 0;
}


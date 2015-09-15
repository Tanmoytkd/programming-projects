#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        switch(n) {
            case 0: return 0;
            case 1: return 0;
            case 2: return 0;
            default: return primecounter(n);
        }
    }
    int primecounter(int n) {
        int primecount=0, length=0;
        int prime[n/2];

        //defining 2 as a prime number
        prime[length]=2;
        length++;


        for(int num=3; num<n; num++) {

            int result=1;
            for(int i=0; i<length; i++) {
                if(prime[i]*prime[i]<=num) {
                    if(num%prime[i]==0) result=0;
                }
                else break;
            }

            if(result==1) {
                prime[length]=num;
                length++;
            }
        }
        return length;
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

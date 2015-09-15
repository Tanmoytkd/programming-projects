#include <iostream>
using namespace std;

class Solution {
public:
    long long int reverse(long long int x) {
        if(x<0) return (0-rev(0-x));
        else return rev(x);
    }

    long long int rev(long long int x) {
        long long int p10=10;
        if(p10>x) return x;
        else {
            long long int numDigit=0, n=x;
            do {
                ++numDigit;
                n /= 10;
            } while (n);


            long long int *digits = new long long int[numDigit];
            for(long long int i=0; i<numDigit; i++) {
                digits[i] = x%10;
                x /= 10;
            }

            p10 = 1;
            long long int res=0;
            for(long long int m=numDigit-1; m>=0; m--) {
                res += digits[m] * p10;
                p10 *=10;
            }

            return res;
        }
    }
};


int main() {
    start:
    cout << "Please enter a number : ";
    long long int num;
    cin >> num;

    Solution sb;
    cout << "The reverse of the number is " << sb.reverse(num) << endl;
    cout << endl;
    goto start;
    return 0;
}

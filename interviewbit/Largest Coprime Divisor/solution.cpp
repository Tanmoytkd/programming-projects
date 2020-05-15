int Solution::cpFact(int A, int B) {
    int gcd;
    do {
        gcd = __gcd(A,B);
        A/=gcd;
    } while(gcd!=1);
    return A;
}


#include <bits/stdc++.h>
using namespace std;

long long primeFactorCount(long long n)
{
    long long cnt = 0;

    if (!(n % 2))
    {
        cnt++;
        while (!(n % 2))
            n /= 2;
    }

    for (long long i = 3; i * i <= n; i = i + 2)
    {
        if (!(n % i))
        {
            cnt++;
            while (!(n % i))
                n /= i;
        }
    }

    if (n > 2)
        cnt++;

    return cnt;
}

long long countABPairs(long long gcd, long long lcm)
{
    if (lcm % gcd != 0)
        return 0;
    long long div = lcm / gcd;
    return (1 << primeFactorCount(div));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while (t--)
    {
        long long c, d, x;
        cin >> c >> d >> x;

        vector<long long> xdivs;

        for (long long i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                xdivs.push_back(i);

                if (i * i != x)
                {
                    xdivs.push_back(x / i);
                }
            }
        }

        long long result = 0;

        for (long long gcd : xdivs)
        {
            if ((x + d * gcd) % c != 0)
            {
                continue;
            }

            long long lcm = (x + d * gcd) / c;

            if (lcm % gcd == 0)
            {
                result += countABPairs(gcd, lcm);
                // if (gcd == lcm) {
                //     result++;
                //     continue;
                // }

                // long long l_by_g = lcm / gcd;

                // for (long long i = 1; i * i <= l_by_g; i++) {
                //     if (l_by_g % i != 0) {
                //         continue;
                //     }

                //     long long j = l_by_g / i;

                //     if (__gcd(i, j) == 1) {
                //         result += 2;
                //     }
                // }
            }
        }

        cout << result << endl;
    }

    return 0;
}
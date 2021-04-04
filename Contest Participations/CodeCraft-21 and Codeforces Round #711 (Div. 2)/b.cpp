#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while (t--)
    {
        long long n, w;
        cin >> n >> w;

        multiset<long long> bricks;
        for (long long i = 0; i < n; i++)
        {
            long long width;
            cin >> width;
            bricks.insert(width);
        }

        long long height = 0;

        while (!bricks.empty())
        {
            height++;

            // vector<multiset<long long>::iterator> toDelete;

            long long total = 0;
            auto it = bricks.upper_bound(w - total);

            while (true)
            {
                if (it == bricks.begin())
                {
                    break;
                }

                it--;

                long long width = *it;

                total += width;
                bricks.erase(it);

                it = bricks.upper_bound(w - total);
            }

            // for (auto it : toDelete) {
            //     bricks.erase(it);
            // }
        }
        cout << height << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> present[m];
        int result[m];

        int occ[n + 1];
        memset(occ, 0, sizeof occ);

        int f = -1;

        for (int day = 0; day < m; day++)
        {
            int k;
            cin >> k;
            int frnd;

            for (int i = 0; i < k; i++)
            {
                cin >> frnd;

                present[day].push_back(frnd);
            }

            int candidate = present[day][0];
            result[day] = candidate;
            occ[candidate]++;

            if (occ[candidate] > (m + 1) / 2)
            {
                f = candidate;
            }
        }

        for (int day = 0; day < m && f != -1 && occ[f] > (m + 1) / 2; day++)
        {
            if (result[day] == f) {
                if (present[day].size() == 1) {
                    continue;
                }

                for (int candidate: present[day]) {
                    if (candidate == f) continue;
                    result[day] = candidate;
                    occ[f]--;
                    break;
                }
            }
        }

        bool impossible = f != -1 && occ[f] > (m + 1) / 2;

        if (impossible)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < m; i++)
            {
                if (i > 0)
                {
                    cout << " ";
                }
                cout << result[i];
            }
            cout << endl;
        }
    }

    return 0;
}
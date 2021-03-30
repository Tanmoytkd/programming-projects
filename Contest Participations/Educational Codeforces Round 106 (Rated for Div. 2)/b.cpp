#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        // cout << "s: " << s << endl;

        bool result = false;

        for (int partition = 0; partition <= s.size(); partition++)
        {
            vector<int> pos;

            bool possible = true;
            for (int i = 0; i < s.size(); i++)
            {
                // cout << i << " '" << s[i] << "'" << endl;
                if ((s[i] == '1' && i < partition) || (s[i] == '0' && i >= partition))
                {
                    pos.push_back(i);
                    // cout << "g" << i << endl;

                    int sz = pos.size();
                    if (pos.size() >= 2 && pos[sz - 1] == pos[sz - 2] + 1)
                    {
                        possible = false;
                        break;
                    }
                }
            }

            if (possible)
            {
                // cout << partition << endl;
                result = true;
                break;
            }
        }

        if (result == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
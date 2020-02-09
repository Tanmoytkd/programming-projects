#include <bits/stdc++.h>
using namespace std;
#define mx ((int)3e5+7)

int last_pos[mx], bit[2*mx+7], n, m, mark[mx], ans[mx];


// updating the bit array
void update(int idx, int val, int n)
{
    for (; idx <= n; idx += idx&-idx)
        bit[idx] += val;
}

// querying the bit array
int query(int idx)
{
    int sum = 0;
    for (; idx>0; idx-=idx&-idx)
        sum += bit[idx];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(last_pos, -1, sizeof last_pos);

    cin >> n >> m;

    int index = 1, num;

    for(num=n; num>0; num--) {
        last_pos[num] = index;
        update(index, 1, n+m);
        index++;
    }

    for(; index<=(n+m); index++) {
        cin >> num;
        mark[num] = 1;

        ans[num] = max(ans[num], query(index)-query(last_pos[num]-1));

        if(last_pos[num]!=-1) {
            update(last_pos[num], -1, n+m);
        }
        last_pos[num] = index;
        update(index, 1, n+m);

    }

    for(num=1; num<=n; num++) {
        ans[num] = max(ans[num], query(index-1)-query(last_pos[num]-1));
    }

    for(int i=1; i<=n; i++) {
        if(mark[i]) cout << 1 << " ";
        else cout << i << " ";

        cout << ans[i] << endl;
    }

    return 0;
}

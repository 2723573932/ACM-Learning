#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, x, y, p, q, op, z;
    cin >> n >> m >> x >> y;
    char mp[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            // mp[2 * i][2 * j] = mp[2 * i][j] = mp[i][2 * j] = mp[i][j];
        }
    cin >> p >> q;
    pair<int, int> ops[q];
    for (int i = 0; i < q; i++)
    {
        cin >> op >> z;
        ops[i] = {op, z};
    }
    for (int i = 1; i <= p; i++)
    {
        for (auto it : ops)
        {
            z=it.second;
            if (it.first & 1)
            {
                mp[z][0] = mp[z][m];
                for (int j = m; j > 0; j--)
                    mp[z][j] = mp[z][j - 1];
            }
            else
            {
                mp[0][z] = mp[n][z];
                for (int j = n; j > 0; j--)
                    mp[j][z] = mp[j - 1][z];
            }
        }
    }
    cout<<mp[x][y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}

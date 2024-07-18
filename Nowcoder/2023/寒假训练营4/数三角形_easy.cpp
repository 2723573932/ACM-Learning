#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    char mp[n + 1][m + 1];
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '*'&&mp[i][j-1] == '*')
                st.insert({i, j});
        }
    for (auto it : st)
    {
        int i = it.first;
        int j = it.second;
        {
            int x = 1;
            while (i - x > 0 && j - x > 0 && j + x <= m)
            {
                if (mp[i][j - x] == '*' && mp[i][j + x] == '*')
                {
                    int f = 1;
                    for (int t = 1; t <= x; t++)
                    {
                        if (mp[i - t][j - x + t] == '*' && mp[i - t][j + x - t] == '*')
                            continue;
                        else
                        {
                            f = 0;
                            break;
                        }
                    }
                    if (f)
                        ans++;
                }
                else
                    break;
                x++;
            }
        }
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}

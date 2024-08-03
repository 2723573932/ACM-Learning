#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> e(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j] && b[i] > b[j])
            {
                e[i].push_back(j);
            }
            else if (a[i] < a[j] && b[i] < b[j])
            {
                e[j].push_back(i);
            }
            else
            {
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
    }
    vector<bool> vis(n + 1, false);
    auto dfs = [&](auto self, int u, int d) -> bool
    {
        if (d == n)
            return true;
        for (const auto &v : e[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                if (self(self, v, d + 1))
                    return true;
                vis[v] = false;
            }
        }
        return false;
    };
    for (int i = 1; i <= n; i++)
    {
        fill(vis.begin(), vis.end(), false);
        vis[i] = true;
        if (dfs(dfs, i, 1))
        {
            cout << "1";
            continue;
        }
        cout << '0';
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int mp[n + 1][n + 1];
    memset(mp, 0, sizeof(mp));
    int a, b, w;
    while (m--)
    {
        cin >> a >> b >> w;
        mp[a][b] = w;
        mp[b][a] = w;
    }
    int t;
    cin >> t;
    vector<int> cost(t + 1);
    for (int i = 1; i <= t; i++)
    {
        int x, f = 1;
        cin >> x;
        int vis[203], to, from = 0;
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < x; j++)
        {
            cin >> to;
            if (mp[from][to] == 0 || vis[to] == 1)
            {
                f = 0;
            }
            cost[i] += mp[from][to];
            vis[to] = 1;
            from = to;
        }
        if (mp[from][0] != 0)
        {
            cost[i] += mp[from][0];
        }
        else
        {
            f = 0;
        }
        if (f == 0||x!=n)
            cost[i] = -1;
    }
    int ans = 0;
    int minx = INT_MAX, x;
    for (int i = 1; i <= t; i++)
    {
        if (cost[i] != -1)
        {
            ans++;
            if (minx > cost[i])
            {
                minx = cost[i], x = i;
            }
        }
    }
    cout << ans << '\n'
         << x << ' ' << minx;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //	cin>>tt;
    while (tt--)
        solve();
}
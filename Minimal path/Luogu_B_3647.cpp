//多源最短路径
#include <bits/stdc++.h>
using namespace std;
int mp[103][103];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                mp[i][j] = 0;
            else
                mp[i][j] = 0x7ffff;
    int u, v, w;
    while (m--)
    {
        cin >> u >> v >> w;
        mp[u][v] = min(mp[u][v], w);
        mp[v][u] = min(mp[v][u], w);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (mp[i][j] > mp[i][k] + mp[k][j])
                    mp[i][j] = mp[i][k] + mp[k][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << mp[i][j] << ' ';
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

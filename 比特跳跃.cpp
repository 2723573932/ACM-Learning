#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> mp(n + 3, vector<ll>(n + 3));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mp[i][j] = k * (i | j);
    while (m--)
    {
        ll u, v, t;
        cin >> u >> v >> t;
        mp[u][v] = min(mp[u][v], t);
        mp[v][u] = min(mp[v][u], t);
    }
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push(make_pair(0, 1));

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (int v = 1; v <= n; v++)
        {
            if (u != v)
            {
                if (dist[u] + mp[u][v] < dist[v])
                {
                    dist[v] = dist[u] + mp[u][v];
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {

        cout << dist[i] << " ";
    }
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

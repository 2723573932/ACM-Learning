#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge
{
    ll to, w, d;
};
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<edge> e[n + 1];
    while (m--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        e[a].push_back({b, c, d});
        e[b].push_back({a, c, d});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    ll ans1 = 0x3f3f3f3f3f, ans2 = 0x3f3f3f3f3f;
    vector<ll> dist(n + 1, 0x3f3f3f3f3f);
    dist[1] = 0;
    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (dist[u] < w)
            continue;
        for (const auto &[v, w, d] : e[u])
        {
            if (d == 1)
            {

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    ans1 = dist[n];
    ans2 = dist[k];
    pq.push({0, k});
    fill(dist.begin(), dist.end(), 0x3f3f3f3f3f);
    dist[k] = 0;
    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        if (dist[u] < w)
            continue;
        for (const auto &[v, w, d] : e[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    ans2 += dist[n];
    cout << (min(ans1, ans2) < 0x3f3f3f3f3f ? min(ans1, ans2) : -1) << '\n';
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

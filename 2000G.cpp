#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 0x3f3f3f3f;
void solve()
{
    int n, m, t0, t1, t2;
    cin >> n >> m >> t0 >> t1 >> t2;
    vector<vector<array<int, 3>>> e(n + 1);
    while (m--)
    {
        int u, v, l1, l2;
        cin >> u >> v >> l1 >> l2;
        e[u].push_back({v, l1, l2});
        e[v].push_back({u, l1, l2});
    }
    vector<int> dis(n + 1, -1);
    priority_queue<pair<int, int>> pq;
    pq.emplace(t0, n);
    while (!pq.empty())
    {
        auto [t, u] = pq.top();
        pq.pop();
        if (dis[u] != -1)
            continue;
        dis[u] = t;
        for (auto [v, l1, l2] : e[u])
        {
            int tmp;
            if (!(t <= t2 && t >= t1) && (t - l1 >= t2 || t <= t1))
                tmp = t - l1;
            else
                tmp = t1 - l1;
            tmp = max(tmp, t - l2);
            if (tmp >= 0)
                pq.emplace(tmp, v);
        }
    }
    cout<<dis[1]<<'\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

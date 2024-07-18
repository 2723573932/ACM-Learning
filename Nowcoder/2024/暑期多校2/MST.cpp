#include <bits/stdc++.h>
using namespace std;
// #define int long long
class DSU
{
public:
    vector<int> parent, rank;
    DSU(int n) : parent(n + 1), rank(n + 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            if (rank[x] < rank[y])
                swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    map<pair<int, int>, int> mp;
    vector<vector<pair<int, int>>> mps(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v)
            swap(u, v);
        mp[{u, v}] = w;
        mps[u].emplace_back(v, w);
    }
    DSU dsu(n);
    while (q--)
    {
        int k;
        long long ans = 0;
        cin >> k;
        unordered_set<int> lst(k);
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < k; i++)
        {
            int tmp;
            cin >> tmp;
            dsu.parent[tmp] = tmp;
            dsu.rank[tmp] = 0;
            lst.insert(tmp);
        }
        if (k <= 300)
        {
            for (const auto &x : lst)
            {
                for (const auto &y : lst)
                {
                    if (mp.count({x, y}))
                        edges.emplace_back(mp[{x, y}], x, y);
                }
            }
        }
        else
        {
            for (const auto &x : lst)
            {
                for (const auto &[y, w] : mps[x])
                {
                    if (lst.count(y))
                        edges.emplace_back(w, x, y);
                }
            }
        }
        sort(edges.begin(), edges.end(), [](const auto &a, const auto &b)
             { return get<0>(a) < get<0>(b); });
        for (const auto &[w, u, v] : edges)
        {
            if (!dsu.connected(u, v))
            {
                dsu.unite(u, v);
                ans += w;
                k--;
                if (k == 1)
                    break;
            }
        }
        if (k != 1)
            ans = -1;
        cout << ans << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
class DSU
{
private:
    vector<int> parent, rank;

public:
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
    vector<vector<int>> mps(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mp[{u, v}] = w;
        mp[{v, u}] = w;
        mps[u].emplace_back(v);
        mps[v].emplace_back(u);
    }
    while (q--)
    {
        int k;
        long long ans = 0;
        cin >> k;
        set<int> lst;
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < k; i++)
        {
            int tmp;
            cin >> tmp;
            lst.insert(tmp);
        }
        if (k * k <= n)
        {
            for (const auto &x : lst)
            {
                for (const auto &y : lst)
                {
                    if (x != y && mp.count({x, y}))
                        edges.emplace_back(mp[{x, y}], x, y);
                }
            }
            DSU dsu(n);
            sort(edges.begin(), edges.end());
            for (const auto &[w, u, v] : edges)
            {
                if (!dsu.connected(u, v))
                {
                    dsu.unite(u, v);
                    ans += w;
                    k--;
                }
            }
        }
        else
        {
            for (const auto &x : lst)
            {
                for (const auto &y : mps[x])
                {
                    if (lst.count(y) && mp.count({x, y}))
                        edges.emplace_back(mp[{x, y}], x, y);
                }
            }
            DSU dsu(n);
            sort(edges.begin(), edges.end());
            for (const auto &[w, u, v] : edges)
            {
                if (!dsu.connected(u, v))
                {
                    dsu.unite(u, v);
                    ans += w;
                    k--;
                }
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
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

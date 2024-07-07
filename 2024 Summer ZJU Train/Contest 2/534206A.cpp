#include <bits/stdc++.h>
using namespace std;
int mp[103][103];
class DSU
{
public:
    vector<vector<pair<int, int>>> pre;
    vector<vector<int>> rank;
    DSU(int n, int m) : pre(n + 1, vector<pair<int, int>>(m + 1)), rank(n + 1, vector<int>(m + 1, 1))
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pre[i][j] = {i, j};
    }
    pair<int, int> find(pair<int, int> i)
    {
        return pre[i.first][i.second] == i ? i : (pre[i.first][i.second] = find(pre[i.first][i.second]));
    }
    bool unite(pair<int, int> x, pair<int, int> y)
    {
        auto xr = find(x);
        auto yr = find(y);
        if (xr == yr)
            return false;
        if (rank[xr.first][xr.second] < rank[yr.first][yr.second])
            swap(xr, yr);
        rank[xr.first][xr.second] += rank[yr.first][yr.second];
        pre[yr.first][yr.second] = xr;
        return true;
    }
    bool connected(pair<int, int> x, pair<int, int> y)
    {
        return find(x) == find(y);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(mp, 0, sizeof(mp));
    DSU dsu(n, m);
    int tmp = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            if (x == '0')
            {
                mp[i][j] = 1;
                tmp++;
            }
            else if (x == '1')
                mp[i][j] = 2;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j])
            {
                if (mp[i - 1][j])
                    dsu.unite({i, j}, {i - 1, j});
                if (mp[i][j - 1])
                    dsu.unite({i, j}, {i, j - 1});
            }
        }
    set<pair<int, int>> st;
    bool f = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j])
            {
                st.insert(dsu.find({i, j}));
            }
        }
    if (st.size() == 1 && (tmp & 1))
    {
        cout << "Yes\n";
    }
    else
        cout << "No\n";
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
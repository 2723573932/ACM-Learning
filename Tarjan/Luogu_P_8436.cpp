#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> e[(int)1e6];
int cnt;
int dfn[(int)1e6], low[(int)1e6];
// bitset<(int)1e6> vis;
stack<int> st;
vector<vector<int>> ans;
void tarjan(int u, int edge)
{
    dfn[u] = low[u] = ++cnt;
    st.push(u);
    // vis[u] = true;
    for (const auto &[v, num] : e[u])
    {
        if (num == (edge ^ 1))
            continue;
        if (!dfn[v])
        {
            tarjan(v, num);
            low[u] = min(low[u], low[v]);
        }
        // else if (vis[v])
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        vector<int> vec;
        vec.push_back(u);
        while (st.top() != u)
        {
            vec.push_back(st.top());
            st.pop();
        }
        st.pop();
        ans.push_back(vec);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, i * 2});
        e[v].push_back({u, i * 2 + 1});
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i, 0);
        }
    }
    cout << ans.size() << '\n';
    for (const auto &v : ans)
    {
        cout << v.size() << ' ';
        for (int i : v)
        {
            cout << i << ' ';
        }
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

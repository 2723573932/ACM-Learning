#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int LOGN = 17;

vector<int> adj[MAXN];
int f[MAXN][LOGN];
int dep[MAXN], maxn[MAXN];

void dfs(int v, int p, int w)
{
    if(v>w)w=v;
    maxn[v]=w;
    dep[v] = dep[p] + 1;
    f[v][0] = p;
    for (int k = 1; k < LOGN; ++k)
    {
        f[v][k] = f[f[v][k - 1]][k - 1];
    }
    for (int u : adj[v])
    {
        if (u != p)
        {
            dfs(u, v, w);
        }
    }
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int k = LOGN - 1; k >= 0; --k)
    {
        if (dep[f[u][k]] >= dep[v])
        {
            u = f[u][k];
        }
    }
    if (u == v)
        return u;
    for (int k = LOGN - 1; k >= 0; --k)
    {
        if (f[u][k] != f[v][k])
        {
            u = f[u][k];
            v = f[v][k];
        }
    }
    return f[u][0];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    dfs(0, 0,0);
    int q;
    cin >> q;
    while (q--)
    {
        int m;
        cin >> m;
        int u, v;
        cin >> u >> v;
        m -= 2;
        u = lca(u, v);
        while (m--)
        {
            cin >> v;
            u = lca(u, v);
        }
        cout << maxn[u] << "\n";
    }
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

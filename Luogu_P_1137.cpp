#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int next, to, w;
} edge[200007];
int head[100007], vis[100007], cnt, ans[100007];
inline void add_edge(int from, int to)
{
    edge[++cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt;
    edge[cnt].w = 1;
    edge[++cnt].to = from;
    edge[cnt].next = head[to];
    head[to] = cnt;
    edge[cnt].w = -1;
}
void dfs(int node)
{
    if (vis[node])
        return;
    vis[node] = 1;
    for (int i = head[node]; i; i = edge[i].next)
    {
        int TO = edge[i].to;
        ans[TO] = max(ans[node] + edge[i].w,ans[TO]);
        dfs(TO);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    while (m--)
    {
        cin >> x >> y;
        add_edge(x, y);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] - *min_element(ans, ans + n) << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}

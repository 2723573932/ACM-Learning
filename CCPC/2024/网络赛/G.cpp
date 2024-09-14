// 模板
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll V = 5e3 + 3, E = 1e6 + 3, inf = 0x3f3f3f3f3f3f;
struct edge
{
public:
    int to, next;
    ll w;
};
int cnt = 0, head[V];
int maxn;
vector<edge> node(E);
inline void add(int u, int v, ll w)
{
    node[cnt].to = v;
    node[cnt].w = w;
    node[cnt].next = head[u];
    head[u] = cnt++;
}
int s, t, deep[V], gap[V], cur[V];
queue<int> que;
ll sum = 0;
inline void init()
{
    memset(deep, -1, V * sizeof(int));
    memcpy(cur, head, (maxn + 1) * sizeof(int));
}
inline void bfs()
{
    int u, v;
    que.push(t);
    deep[t] = 0;
    ++gap[deep[t]];
    while (!que.empty())
    {
        u = que.front();
        que.pop();
        for (int i = head[u]; i != -1; i = node[i].next)
        {
            v = node[i].to;
            if (deep[v] == -1)
            {
                deep[v] = deep[u] + 1;
                que.push(v);
                ++gap[deep[v]];
            }
        }
    }
}
ll dfs(int u, ll flow)
{
    if (u == t || flow == 0)
        return flow;
    ll used = 0, wei = 0;
    for (int i = cur[u]; i != -1; i = node[i].next)
    {
        cur[u] = i;
        if (deep[u] == deep[node[i].to] + 1 && node[i].w > 0)
        {
            wei = dfs(node[i].to, min(flow - used, node[i].w));
            if (wei)
            {
                node[i].w -= wei;
                node[i ^ 1].w += wei;
                used += wei;
            }
        }
        if (used == flow)
            return used;
    }
    if (used < flow)
    {
        --gap[deep[u]];
        if (!gap[deep[u]])
            deep[s] = maxn + 1;
        ++gap[++deep[u]];
    }
    return used;
}
ll ISAP()
{
    init();
    bfs();
    while (deep[s] < maxn)
    {
        sum += dfs(s, inf);
        memcpy(cur, head, (maxn + 1) * sizeof(int));
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(head, -1, V * sizeof(int));
    int n, m, f = 1;
    cin >> n >> m;
    maxn = n + m + 2;
    s = n + m + 1, t = n + m + 2;
    vector<ll> a(n + 1), v(n + 1);
    ll maxs = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> v[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        if (x == 1 || y == 1)
        {
            maxs += w;
        }
        sum += w;
        add(x, n + i, inf);
        add(n + i, x, 0);
        add(y, n + i, inf);
        add(n + i, y, 0);
        add(n + i, t, w);
        add(t, n + i, 0);
    }
    maxs = min(maxs + v[1], (ll)a[1]);
    if (maxs < 0)
    {
        cout << "NO\n";
        return 0;
    }
    add(s, 1, maxs - v[1]);
    add(1, s, 0);
    for (int i = 2; i <= n; ++i)
    {
        a[i] = min(maxs - 1, a[i]);
        if (a[i] - v[i] < 0)
        {
            cout << "NO\n";
            return 0;
        }
        add(s, i, a[i]-v[i]);
        add(i, s, 0);
    }
    if (ISAP() == sum)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}
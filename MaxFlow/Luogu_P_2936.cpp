// 模板
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll V = 1e3 + 3, E = 1e6 + 3, inf = 0x3f3f3f3f3f3f;
struct edge
{
public:
    int to, next;
    ll w;
};
int cnt = 0, head[V];
int n, m;
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
    memcpy(cur, head, (n + 1) * sizeof(int));
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
            deep[s] = n + 1;
        ++gap[++deep[u]];
    }
    return used;
}
ll ISAP()
{
    init();
    bfs();
    while (deep[s] < n)
    {
        sum += dfs(s, inf);
        memcpy(cur, head, (n + 1) * sizeof(int));
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(head, -1, V * sizeof(int));
    cin >> m;
    n=200;
    s = (int)'A';
    t = (int)'Z';
    for (int i = 0; i < m; i++)
    {
        char u, v;
        ll w;
        cin >> u >> v >> w;
        add((int)u, (int)v, w);
        add((int)v, (int)u, 0);
    }
    cout << ISAP();
    return 0;
}
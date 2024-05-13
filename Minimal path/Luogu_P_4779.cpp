// 单源最短路径
#include <bits/stdc++.h>
using namespace std;

struct EDGE
{
    long long w;
    long long next;
    long long to;
} edge[200003];
long long head[100003], vis[100003], dis[100003];
long long cnt = 0;
inline void add_edge(long long from, long long to, long long w)
{
    edge[++cnt].to = to;
    edge[cnt].next = head[from];
    edge[cnt].w = w;
    head[from] = cnt;
}
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> que;
void solve()
{
    long long n, m, s;
    cin >> n >> m >> s;
    long long from, to, w;
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    dis[s] = 0;
    que.push({0, s});
    while (m--)
    {
        cin >> from >> to >> w;
        add_edge(from, to, w);
    }
    while (!que.empty())
    {
        long long node = que.top().second;
        que.pop();
        if (vis[node])
            continue;
        vis[node] = 1;
        for (long long i = head[node]; i; i = edge[i].next)
        {
            long long To = edge[i].to;
//------------------------------------------------------
            if(dis[To]>dis[node]+edge[i].w)
            {
                dis[To]=dis[node]+edge[i].w;
                if(!vis[To])
                que.push({dis[To],To});
            }
//------------------------------------------------------
        }
    }
    for (long long i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int f[5 * (int)1e5 + 7];
struct Edge
{
    int next, to;
} edge[5 * (int)1e5 + 7];
vector<int> head(5 * (int)1e5 + 7, -1);
int vis[5 * (int)1e5 + 7];
int cnt;
void adge(int from, int to)
{
    edge[cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}
void solve()
{
    int n, m, q, k;
    cin >> n >> m >> q >> k;
    queue<int> que;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        que.push(x);
        f[x] = 0x3f3f3f;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adge(y, x);
    }
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        if (vis[node])
            continue;
        vis[node] = 1;
        for (int i = head[node]; ~i; i = edge[i].next)
        {
            int to = edge[i].to;
            f[to]++;
            if (f[to] > k)
                que.push(to);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]>k)cout<<"S";
        else cout<<"B";
    }
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

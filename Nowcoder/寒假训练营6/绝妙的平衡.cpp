#include <bits/stdc++.h>
using namespace std;
struct EDGE
{
    int to;
    int next;
    int w;
} edge[100007];
int head[100007], vis[100007], color[100007], cnt = 0;
void add_edge(int from, int to)
{
    edge[cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt++;
}
void solve()
{
    memset(head,-1,sizeof(head));
    int n;
    cin>>n;
    char c;
    int fa;
    for(int i=0;i<=n;i++)
    {
        cin>>c;
        if(c == 'R')
        {
            color[i] = 1;
        }
        else
        {
            color[i] = 0;
        }
    }
    for(int i=2;i<=n;i++)
    {
        cin>>fa;
        add_edge(fa,i);
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

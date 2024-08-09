//树的直径
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    vector<int> dis(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    auto dfs = [&](auto self, int u, int fa) -> void
    {
        dis[u] = dis[fa] + 1;
        for (auto v : e[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    int id=1;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>dis[id])
        {
            id=i;
        }
    }
    dis.assign(n+1,0);
    dfs(dfs,id,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dis[i]);
    }
    cout<<ans-1<<'\n';
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

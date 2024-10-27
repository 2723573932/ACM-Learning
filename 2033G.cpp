#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1, vector<int>());
    vector<int> deep(n + 1, 0);
    vector<int> fa(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        fa[v]=u;
    }
    auto dfs = [&](auto &&dfs, int u) -> int {
        int maxdeep = 0;
        for (auto v : e[u])
        {
            maxdeep = max(maxdeep, dfs(dfs, v));
        }
        deep[u] = maxdeep;
        return maxdeep + 1;
    };
    dfs(dfs,1);
    int q;
    cin>>q;
    while(q--)
    {
        int v,k;
        cin>>v>>k;
        int ans=0;
        int tmp=0;
        while(v!=0&&tmp<=k)
        {
            ans=max(ans,deep[v]+tmp);
            v=fa[v];
            tmp++;
        }
        cout<<ans<<" ";
    }
    cout<<'\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

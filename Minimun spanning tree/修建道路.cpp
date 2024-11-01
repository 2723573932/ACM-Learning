#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    vector<int> rank, fa;
    DSU(int n) : rank(n + 1, 1), fa(n + 1)
    {
        iota(fa.begin(), fa.end(),0);
    }
    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            swap(x, y);
        rank[x] += rank[y];
        fa[y] = x;
        return true;
    }
    bool connect(int x, int y)
    {
        return find(x) == find(y);
    }
};
int main()
{
    int n;
    cin >> n;
    DSU dsu(n);
    int ans=0;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    for (int i = 1; i <= n; i++)
    {
        for(int j=1;j<=n;j++)
        {
            int w;
            cin>>w;
            pq.push({w,i,j});
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        dsu.unite(u,v);
    }
    while(!pq.empty())
    {
        auto [w,u,v]=pq.top();
        pq.pop();
        if(dsu.unite(u,v))
        {
            ans+=w;
        }
    }
    cout<<ans;
}
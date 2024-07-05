#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n) : parent(n + 1), rank(n + 1,1)
    {
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot == yroot)
            return false;
        if (rank[xroot] < rank[yroot])
        {
            swap(xroot, yroot);
        }
        rank[xroot] += rank[yroot];
        parent[yroot] = xroot;
        return true;
    }
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};
void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    DSU a(n), b(m);
    while (p--)
    {
        int x, y;
        cin >> x >> y;
        a.unite(x, y);
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        b.unite(-x, -y);
    }
    int x = a.rank[a.find(1)];
    int y = b.rank[b.find(1)];
    cout<<min(x,y)<<'\n';
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

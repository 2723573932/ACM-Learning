#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parents;
    vector<int> sizes;

public:
    DSU(int size) : parents(size+1), sizes(size+1, 1)
    {
        for (int i = 1; i <= size; i++)
        {
            parents[i] = i;
        }
    }
    int find(int x)
    {
        return parents[x] == x ? x : (parents[x] = find(parents[x]));
    }
    bool unite(int x, int y)
    {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root)
        {
            return false;
        }
        if (sizes[x_root] < sizes[y_root])
        {
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    int z, x, y;
    while (m--)
    {
        cin >> z >> x >> y;
        if (z == 1)
        {
            dsu.unite(x, y);
        }
        else
        {
            if (dsu.connected(x, y))
                cout << "Y\n";
            else
                cout << "N\n";
        }
    }
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

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parents;
    vector<int> sizes;
    DSU(int size) : parents(size), sizes(size, 1)
    {
        for (int i = 0; i < size; i++)
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
    list<pair<int, int>> lst;
    unordered_set<int> st;
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        lst.push_back({x, y});
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    while (!st.empty())
    {
        for (auto it = lst.begin(); it != lst.end(); it++)
        {
            if (st.find(it->first) != st.end() || st.find(it->second) != st.end())
            {
                dsu.unite(it->first, it->second);
                lst.erase(it);
            }
        }
        ans.push_back(dsu.sizes.size());
        auto it=st.end();
        it--;
        st.erase(it);
    }
    for (auto it = ans.rbegin(); it < ans.rend(); it++)
        cout << *it << '\n';
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

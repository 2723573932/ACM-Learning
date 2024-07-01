#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> pre;
    vector<int> rank;

public:
    DSU(int n) : pre(n), rank(n, 1)
    {
        for (int i = 0; i < n; i++)
            pre[i] = i;
    }
    int find(int x)
    {
        return pre[x] == x ? x : (pre[x] = find(pre[x]));
    }
    bool unite(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot == yroot)
            return false;
        else
        {
            if (rank[xroot] < rank[yroot])
                swap(xroot, yroot);
            rank[xroot] += yroot;
            pre[yroot] = xroot;
        }
        return true;
    }
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    stack<int> ans;

    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    DSU dsu(n);
    int k;
    cin >> k;
    deque<int> lst(k);
    bool tmp[n + 1];
    memset(tmp,0,sizeof(tmp));
    int count = n - k;
    unordered_map<int, vector<pair<int, int>>> mp;
    for (auto &i : lst)
    {
        cin >> i;
        tmp[i] = 1;
    }
    for (const auto &i : a)
    {
        if (tmp[i.first] || tmp[i.second])
        {
            if (tmp[i.first])
                mp[i.first].push_back(i);
            if (tmp[i.second])
                mp[i.second].push_back(i);
        }
        else
        {
            if (dsu.unite(i.first, i.second))
                count--;
        }
    }
    ans.push(count);
    for (auto it = lst.rbegin(); it != lst.rend(); it++)
    {
        count++;
        tmp[*it]=0;
        for (const auto i : mp[*it])
        {
            if (tmp[i.first] || tmp[i.second])
            continue;
            if (dsu.unite(i.first, i.second))
                count--;
        }
        ans.push(count);
    }
    while (!ans.empty())
    {
        cout << ans.top() << '\n';
        ans.pop();
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

#include <bits/stdc++.h>
using namespace std;

int ans[(int)1e7 + 5];
vector<vector<int>> G((int)2e7 + 5);
int getmax(int x)
{
    if (ans[x] != 0)
        return ans[x];
    int res = 1;
    for (auto i : G[x])
        res = max(res, getmax(i) + 1);
    return ans[x] = res;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(ans, 0, sizeof(ans));
    while (m--)
    {
        int v, u;
        cin >> v >> u;
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << getmax(i) <<"\n";
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

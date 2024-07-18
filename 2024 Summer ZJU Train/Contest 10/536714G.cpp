#include <bits/stdc++.h>
using namespace std;
struct EDGE
{
    int to, next;
} edge[(int)1e5 + 7];
vector<int> head((int)1e5 + 7, -1);
int cnt;
void adge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
long long dfs(int node, const int &m, long long &k)
{
    long long ans = 1;
    for (int i = head[node]; i != -1; i = edge[i].next)
    {
        ans += dfs(edge[i].to, m, k);
    }
    if (ans > m)
    {
        ans = 0;
        k--;
    }
    return ans;
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adge(x, i);
    }
    long long l = 1, r = (n + k) / (k + 1);
    while (l < r)
    {
        long long m = (l + r) / 2;
        long long kk = k;
        dfs(1, m, kk);
        if (kk >= 0)
            r = m;
        else
            l = m + 1;
    }
    cout << r << '\n';
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
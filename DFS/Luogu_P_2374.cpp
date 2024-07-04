#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], c[100];
int dfs(int i, int j, int k, int t)
{
    if (i == 0 && j == 0 && k == 0)
    {
        return 0;
    }
    int x, y, z;
    x = y = z = 0;
    if (i != 0)
        x = dfs(i - 1, j, k, t+1) + a[i] * t;
    if (j != 0)
        y = dfs(i, j - 1, k, t+1) + b[j] * t;
    if (k != 0)
        z = dfs(i, j, k - 1, t+1) + c[k] * t;
    return max(x, max(y, z));
}
void solve()
{
    int i, j, k;
    cin >> i >> j >> k;
    for (int x = 1; x <= i; x++)
    {
        cin >> a[x];
    }
    for (int x = 1; x <= j; x++)
    {
        cin >> b[x];
    }
    for (int x = 1; x <= k; x++)
    {
        cin >> c[x];
    }
    cout << dfs(i, j, k, 1);
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

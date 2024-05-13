// 完全背包
#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[20000007], w[20000007], t[20000007];
void solve()
{
    int T, M;
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
        cin >> t[i] >> w[i];
    for (int i = 1; i <= M; i++)
        for (int v = t[i]; v <= T; v++)
            if (f[v - t[i]] + w[i] >= f[v])
                f[v] = f[v - t[i]] + w[i];
    cout << f[T];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}

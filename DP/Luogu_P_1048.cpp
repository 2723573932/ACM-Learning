//01背包问题
#include <bits/stdc++.h>
using namespace std;

int f[5000], w[5000], t[5000];
void solve()
{
    int T, M;
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
        cin >> t[i] >> w[i];
    for (int i = 1; i <= M; i++)
        for (int v = T; v >= t[i]; v--)
            if (f[v - t[i]] + w[i] >= f[v])
                f[v] = f[v - t[i]] + w[i];
    cout<<f[T];
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

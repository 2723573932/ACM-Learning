#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    int ans = 0;
    vector<long long> v(4 * n + 100);
    for (int k = 1; k <= n; ++k)
    {
        int tmp = 0;
        for (int i = 1; i * k <= 2*n && i <= n; i++)
        {
            int x = p[i] - k * i + 2 * n;
            ans += v[x];
            v[k * i - p[i] + 2 * n]++;
        }
        for(int i = 1; i * k <= 2*n && i <= n; i++)
        {
            v[k * i - p[i] + 2 * n] --;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

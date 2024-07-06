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

    for (int k = 1; k <= n; ++k)
    {
        unordered_map<int, int> m1, m2;
        int tmp = 0;
        for (int i = 1; i * k <= n; i++)
        {
            if (p[i] - k * i > 0)
                m1[p[i] - k * i]++;
            else if (p[i] - k * i < 0)
                m2[k * i - p[i]]++;
            else
                tmp++;
        }
        ans += tmp * (tmp - 1) / 2;
        for (const auto &[key, value] : m1)
        {
            ans += value * m2[key];
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

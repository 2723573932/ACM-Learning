#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll dp[1000005];
ll last[26];
ull base = 131;
const ll mod = 1e9 + 7;
void solve()
{
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    ll pos = 0, repos = n - 1;
    ll p = 0;
    ll ans = 0;
    while (p < m && pos < n)
    {
        if (s[pos] == t[p])
            p++;
        pos++;
    }
    if (p != m)
    {
        cout << 0;
        return;
    }
    p = 0;
    while (repos >= pos && p < m)
    {
        if (s[repos] == t[p])
            p++;
        repos--;
    }
    for (ll i = pos; i <= repos; i++)
    {
        if (!last[s[i] - 'a'])
            (dp[i] = 2 * dp[i - 1] + 1) %= mod;
        else
            (dp[i] = 2 * dp[i - 1] + mod - dp[last[s[i] - 'a'] - 1]) %= mod;
        last[s[i] - 'a'] = i;
    }
    ans = dp[repos];
    if (pos <= repos+1&&p!=0)
        ans++;

    ull pre = 0, suf = 0;
    ull pw = 1;
    for (ll i = 0; i < m; i++)
    {
        pre = pre * base + t[m - i - 1];
        suf = suf + pw * t[m - i - 1];
        pw *= base;
        if (pre == suf && i >= m - p-1)
            ans++;
    }
    cout << ans % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

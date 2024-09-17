#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1e9 + 7;
ll qpow(ll a, ll b = mod - 2)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x : a)
    {
        cin >> x;
        (sum += x) %= mod;
    }
    ll ans = 0;
    for (const auto &x : a)
    {
        sum -= x;
        if (sum < 0)
            sum += mod;
        (ans += x * sum % mod) %= mod;
    }
    ll tmp = qpow(n * (n - 1LL) / 2 % mod);
    ans = tmp * ans % mod;
    cout << ans << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

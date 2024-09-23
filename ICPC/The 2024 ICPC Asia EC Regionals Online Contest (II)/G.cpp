#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 998244353;
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
    ll x, y, a0, a1, b;
    cin >> x >> y >> a0 >> a1 >> b;
    ll p0 = a0 * qpow(a0 + a1) % mod;
    ll p1 = a1 * qpow(a0 + a1) % mod;
    auto dfs = [&](auto self, ll x, ll y) -> ll
    {
        if (x > y)
        {
            if (x % y == 0)
                return ((mod + 1 - qpow(p1, x / y -1)) % mod + qpow(p1, x / y -1)*p0 % mod) % mod;
            ll n = x / y;
            return (qpow(p1, n) * self(self, x - n * y, y) % mod + (1 + mod - qpow(p1, n))%mod) % mod;
        }
        else
        {
            if (y % x == 0)
                return qpow(p0, y / x) % mod;
            ll n = y / x;
            return qpow(p0, n) * self(self, x, y - n * x) % mod;
        }
    };
    cout << dfs(dfs, x, y) << '\n';
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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1e9 + 7;
vector<ll> invfac(2e5 + 7);
vector<ll> fac(2e5 + 7);
ll qpow(ll a, ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1)
        {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
ll ini()
{
    fac[0] = 1;
    for (int i = 1; i < 2e5 + 7; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    invfac[2e5 + 6] = qpow(fac[2e5 + 6], mod - 2);
    for (int i = 2e5 + 5; i >= 0; i--)
    {
        invfac[i] = invfac[i + 1] * (i + 1) % mod;
    }
    return 0;
}
ll c(ll n, ll m)
{
    if (m > n)
        return 0;
    if (m == 0)
        return 1;
    return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll x = count(a.begin(), a.end(), 0);
    ll y = n - x;
    ll ans = 0;
    for (int i = 0; i <= k / 2; i++)
    {
        (ans += c(x, i) * c(y, k - i) % mod) %= mod;
    }
    cout << ans << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    ini();
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

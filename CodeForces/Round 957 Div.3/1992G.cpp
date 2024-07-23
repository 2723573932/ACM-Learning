#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fact[5003];
ll invfact[5003];
ll mod = 1e9 + 7;
ll qpow(ll a, ll b)
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
void ini()
{
    fact[0] = 1;
    for (int i = 1; i <= 5000; i++)
        fact[i] = fact[i - 1] * i % mod;
    invfact[5000] = qpow(fact[5000], mod - 2);
    for (int i = 4999; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
}
ll C(int n, int m)
{
    if (n < m)
        return 0;
    return fact[n] * invfact[m] % mod * invfact[n - m] % mod;
}
void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int a = 1; a <= n; a++)
    {
        for (int x = 0; x <= a - 1; x++)
        {
            int y = a - 1 - 2 * x;
            if (y < 0)
                break;
            if (n - a >= y)
                ans = (ans + C(a - 1, x) * C(n - a, y) % mod * a % mod) % mod;
        }
    }
    for (int a = n + 1; a <= n + n + 1; a++)
    {
        if (a % 2 == 1)
            ans = (ans + C(n, a / 2) * a % mod) % mod;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    ini();
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

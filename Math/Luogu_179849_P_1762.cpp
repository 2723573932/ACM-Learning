//杨辉三角
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000003;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    bitset<64> bits(n);
    ll ans = (n % mod) * (n % mod + 1) / 2 % mod, tmp = 1;
    for (int i = 63; i >= 0; i--)
    {
        if (bits[i])
        {
            ans = (ans + mod - qpow(3, i) % mod * tmp % mod) % mod;
            tmp = tmp * 2 % mod;
        }
    }
    cout << ans << '\n';
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

#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 1e9 + 7;
long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    long long lst[m];
    for (int i = 0; i < m; i++)
    {
        cin >> lst[i];
    }
    long long x, y;
    long long sigma = 0;
    for (int i = 0; i < m; i++)
    {
        exgcd(lst[i] + 1e6, mod, x, y);
        sigma = (sigma + (lst[i] % mod * ((x % mod + mod) % mod))) % mod;
    }
    exgcd((sigma+mod)%mod, mod, x, y);
    exgcd((x - 1+mod)%mod, mod, x, y);
    cout << n * (x % mod + mod) % mod << endl;
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

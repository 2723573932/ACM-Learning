//线性求逆元
#include <bits/stdc++.h>
using namespace std;

long long inv[(long long)1e8];
void solve()
{
    long long n, p;
    cin >> n >> p;
    inv[1] = 1;
    for (long long i = 2; i <= n; i++)
    {
        inv[i] = (p - p / i * inv[p % i] % p) % p;
    }
    for(long long i=1;i<=n;i++)
    {
        cout<<inv[i]<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}

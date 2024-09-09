#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 998244353;
ll lst[1007];
void ini()
{
    lst[1] = 1;
    for (int i = 2; i < 1007; i++)
    {
        lst[i] = lst[i - 1] * i % mod;
    }
}
void solve()
{
    ini();
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "0 1\n";
        return;
    }
    map<ll, ll> mp;
    while (n--)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll cnt = 2, sum = 0;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        for (auto j = next(i); j != mp.end(); j++)
        {
            sum += (j->first - i->first) * i->second * j->second;
        }
    }
    if (mp.size() == 1)
    {
        cnt = 1;
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        (cnt *= lst[i->second]) %= mod;
    }
    cout << sum << ' ' << cnt << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

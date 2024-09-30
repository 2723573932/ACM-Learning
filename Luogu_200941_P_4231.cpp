#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
map<ll, ll> a, b;
void print(__int128 x)
{
    if (x > 9)
        print(x / 10);
    cout<<char(x % 10 + '0');
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (ll i = 1; i <= m; i++)
    {
        int l, r, s, e;
        cin >> l >> r >> s >> e;
        ll tmp = (e - s) / (r - l);
        a[l] += s - tmp;
        a[r + 1] -= s - tmp;
        b[l] += tmp;
        b[r + 1] -= e - s + 2 * tmp;
    }
    ll ans = 0, maxn = 0;
    ll tmp = 0, add = 0;
    ll c1, c2 = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (a.contains(i))
            tmp += a[i];
        if (b.contains(i))
            c1 = c2 + b[i];
        add += c1;
        swap(c1, c2);
        ans ^= tmp + add;
        maxn = max(maxn, tmp + add);
    }
    print(ans);
    cout<<' ';
    print(maxn);
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    ll tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

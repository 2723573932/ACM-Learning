#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), pre(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        b[i] = c == 'L' ? 0 : 1;
    }
    ll l = 1, r = n, ans = 0;
    while (l < r)
    {
        while (b[l] && l <= n)
            l++;
        if (l > r)
            break;
        while (!b[r] && r > 0)
            r--;
        if (l > r)
            break;
        ans += pre[r] - pre[l - 1];
        l++, r--;
    }
    cout << ans << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    ll tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

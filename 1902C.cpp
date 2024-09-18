#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    unordered_set<ll> st;
    ll maxn = -INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        st.insert(x);
        maxn = max(maxn, x);
    }
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    ll gd = 0;
    for (const auto &i : st)
    {
        if (maxn - i == 0)
            continue;
        if (gd == 0)
            gd = maxn - i;
        gd = gcd(gd, maxn - i);
    }
    ll ans = 0;
    for (const auto &i : st)
        ans += (maxn - i) / gd;
    for (ll i = 1; i < n; i++)
    {
        if (!st.contains(maxn - i * gd))
        {
            cout << ans + i << '\n';
            return;
        }
    }
    cout << ans + n << '\n';
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

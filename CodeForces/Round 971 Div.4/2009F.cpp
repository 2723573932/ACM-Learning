#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), pre(1);
    for (ll &x : a)
    {
        cin >> x;
        pre.emplace_back(pre.back() + x);
    }
    for (ll &x : a)
    {
        pre.emplace_back(pre.back() + x);
    }
    while (q--)
    {
        ll ans = 0;
        ll l, r;
        cin >> l >> r;
        l--, r--;
        ll i=l/n, j=r/n;
        l%=n;
        r%=n;
        ans=pre[n]*(j-i+1)-(pre[i+l]-pre[i])-(pre[j+n]-pre[j+r+1]);
        cout<<ans<<'\n';
    }
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

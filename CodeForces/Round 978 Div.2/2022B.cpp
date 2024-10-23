#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, x;
    cin >> n >> x;
    ll ans = 0, sum = 0;
    while (n--)
    {
        ll x;
        cin >> x;
        sum += x;
        ans=max(ans,x);
    }
    cout<<max<ll>(ans,(sum+x-1)/x)<<'\n';
}
main()
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

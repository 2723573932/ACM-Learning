#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, b;
    cin >> n >> b;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<ll>());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans+=a[i];
        if(ans>=b)
        {
            cout<<i+1<<'\n';
            return;
        }
    }
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

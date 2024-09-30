#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    unordered_map<ll, ll> mp;
    for(int i=1;i<=n;i++)
    {
        mp[(i-1)*(n-i)+i-1+n-i]++;
        if(i>1)
        {
            mp[(i-1)*(n-i+1)]+=a[i]-a[i-1]-1;
        }
    }
    while (q--)
    {
        ll x;
        cin>>x;
        if(mp.contains(x))
        cout<<mp[x]<<' ';
        else
        {
            cout<<"0 ";
        }
    }
    cout << '\n';
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

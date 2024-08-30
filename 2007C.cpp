#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    ll a, b;
    cin >> n >> a >> b;
    a=gcd(a,b);
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]%=a;
    }
    sort(v.begin(),v.end());
    ll ans=v.back()-v[0];
    for(int i=1;i<n;i++){
        ans=min(ans,a-v[i]+v[i-1]);
    }
    cout << ans<<'\n';
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

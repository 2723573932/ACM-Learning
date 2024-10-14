#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), pref(n + 1), suff(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        pref[i] = gcd(pref[i - 1], a[i]);
        suff[n - i + 1] = gcd(suff[n - i + 2], a[n - i + 1]);
    }
    ll ans = pref[n];
    for(int i=1;i<=n;++i)
    {
        if(pref[i]==pref[i-1])continue;
        ll tmp=0;
        for(int j=i;j<=n;j++)
        {
            tmp=gcd(tmp,a[j]+k);
            ans=max(ans,gcd(gcd(pref[i-1],tmp),suff[j+1]));
        }
    }
    cout<<ans<<'\n';
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

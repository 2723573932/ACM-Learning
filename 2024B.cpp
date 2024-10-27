#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll sum=0,ans=0,tmp=0;
    for(auto [x,y]:mp)
    {
        if(sum+(x-tmp)*n>=k)
        {
            ans+=k-sum;
            break;
        }
        else{
            sum+=(x-tmp)*n;
            ans+=(x-tmp)*n;
            ans+=y;
            n-=y;
            tmp=x;
        }
    }
    cout << ans << '\n';
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

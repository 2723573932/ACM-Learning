#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    ll n,m;
    cin>>m>>n;
    set<ll> s;
    for(ll i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        s.insert(x);
    }
    ll ans=0;    
    while(n--)
    {
        ll x;
        cin>>x;
        auto it=s.lower_bound(x);
        if(it==s.end())
        {
            ans+=x-*(prev(it));
        }
        else if(it==s.begin())
        {
            ans+=*it-x;
        }
        else
        {
            ans+=min(*it-x,x-*(prev(it)));
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
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
system("pause");
#endif
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
ll qpow(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    ll sum,tmp,x;
    sum=tmp=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        (sum+=x)%=mod;
        tmp
    }
    cout<<ans*qpow(n*(n-1)/2,mod-2)%mod<<'\n';
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

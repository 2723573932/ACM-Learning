#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
ll qpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void solve()
{
    ll n;
    cin>>n;
    ll ans=0;
    ll tmp=1;
    if(n==1)cout<<"0";
    else if(n==2)cout<<"1";
    else
    {
        cout<<qpow(2,n-1LL)%mod*(n-2LL)%mod+1LL;
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
/*
3
1 3 3 1
0 0 1 2
1 5 10 10 5 1
1 6 15 20 15 6 1
0 0 1  2  3  4 5 
1 7 21 35 35 21 7 1
0 0 1  2  3  4  5 6
15+40+45+24+5=
*/
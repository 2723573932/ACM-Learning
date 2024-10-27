#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
void solve()
{
    ll n,k;
    cin>>n>>k;
    auto fib=[&]()->ll{
        ll a=1%k,b=1%k,n=3;
        if(a==0)return 1;
        while((a+b)%k!=0)
        {

            ll c=a;
            a=b%k;
            (b+=c)%=k;
            n++;
        }
        return n;
    };
    cout<<n%mod*fib()%mod<<'\n';

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

#include <bits/stdc++.h>
using namespace std;
using i128= __int128;
using ll = long long;
i128 sum(i128 n)
{
    return n * (n - 1) / 2;
}
void solve()
{
    ll nn, kk;
    cin >> nn >> kk;
    i128 n=nn,k=kk;
    i128 l=1,r=n;
    i128 mid=(l+r)>>1;
    i128 maxn=sum(n);
    while(l<r)
    {
        mid=(l+r)>>1;
        i128 tmp=maxn-sum(mid)*2+k*(n-mid*2);
        if(tmp>0)
        {
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    l--;
    ll ans=min(maxn-sum(l)*2+k*(n-l*2),-(maxn-sum(r)*2+k*(n-(r)*2)));
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

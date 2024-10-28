#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    ll a,b;
    cin>>a>>b;
    ll l=0,r=a;
    while(l<r)
    {
        ll m=(l+r)>>1;
        if(b-2*m<=a-m)
            r=m;
        else
            l=m+1;
    }
    if(b-2*l>a-l)
    l++;
    cout<<max(0ll,a-l)<<'\n';
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

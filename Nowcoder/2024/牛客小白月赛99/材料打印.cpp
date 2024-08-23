#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    ll ans=0,a,b,x,y;
    cin>>a>>b>>x>>y;
    cout<<b*y+a*min(x,y)<<'\n';

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

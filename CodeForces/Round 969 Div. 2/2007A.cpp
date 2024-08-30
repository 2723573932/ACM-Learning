#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    if(r-l+1<3){
        cout<<"0\n";
        return;
    }
    int ans=0;
    if(l&1)
    {
        ans=1;
        l+=3;
    }
    ans+=(r-l+1)/4;
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

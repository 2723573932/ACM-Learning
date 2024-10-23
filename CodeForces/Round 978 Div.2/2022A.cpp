#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,r;
    cin>>n>>r;
    int ans=0;
    int tmp=0;
    while(n--)
    {
        int x;
        cin>>x;
        ans+=x/2;
        r-=x/2;
        tmp+=(x&1);
    }
    ans*=2;
    if(r>=tmp)ans+=tmp;
    else{
        ans+=2*r-tmp;
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

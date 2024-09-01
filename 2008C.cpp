#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long l,r;
    cin>>l>>r;
    int ans=0;
    int p=l,q=1;
    while(p<=r)
    {
        ans++;
        p+=q;
        q++;
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

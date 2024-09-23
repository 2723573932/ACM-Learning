#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    ll sum=1500;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        sum+=x;
        if(sum>=4000)
        {
            cout<<i;
            return;
        }
    }
    cout<<-1;
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

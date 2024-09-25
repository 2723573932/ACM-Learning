#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<ll> lst(n);
    for (int i = 0; i < n; i++)
        cin >> lst[i];
    sort(lst.begin(), lst.end());
    ll maxn=lst.back();
    ll ans = 0;
    ll gd=lst.back()-lst[0];
    for(int i=1;i<n;i++)
    {
        gd=gcd(gd,lst[i]-lst[i-1]);
    }
    gd=max(1ll,gd);
    for(int i=0;i<n;i++)
    {
        ans+=(maxn-lst[i])/gd;
    }
    int p=n-1;
    ll i=-1;
    while(p>=0)
    {
        if(lst[p]==maxn-gd*++i)
        {
            p--;
        }
        else
        {
            ans+=i;
            cout<<ans<<'\n';
            return;
        }
    }
    cout<<ans+n<<'\n';
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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, x;
    cin >> n >> x;
    unordered_multiset<ll> s;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        s.insert(a);
    }
    ll ans=0;
    int f=0;
    while(!s.empty()){
        f=0;
        for(int i=0; ans-i*x>=0;i++){
            if(s.contains(ans-i*x)){
                s.erase(s.find(ans-i*x));
                ans++;
                f=1;
            }
        }
        if(!f)break;
    }
    cout<<ans<<endl;
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

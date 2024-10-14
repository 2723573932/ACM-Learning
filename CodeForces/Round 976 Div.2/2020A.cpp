#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n <<'\n';
        return;
    }
    vector<ll> v;
    while (n)
    {
        v.push_back(n % k);
        n /= k;
    }
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans+=v[i];
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

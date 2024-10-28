#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin >> n;
    vector<array<ll, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    sort(a.begin(), a.end(), [](array<ll, 3> a, array<ll, 3> b)
         {
        if(a[0]+a[1]+a[2]==b[0]+b[1]+b[2])
        {
            return a[0]+a[1]<b[0]+b[1];
        }
        return a[0]+a[1]+a[2]<b[0]+b[1]+b[2]; });
    ll ans = 0;
    ll t = 0;
    for (const auto &[s, a, e] : a)
    {
        ans += t + s + a;
        t += s + a + e;
    }
    cout << ans << '\n';
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

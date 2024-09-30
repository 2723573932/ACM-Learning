#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n);
    double sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (n <=2)
    {
        cout << "-1\n";
        return;
    }
    sort(a.begin(), a.end());
    ll l = 0, r = 0x3f3f3f3f3f3f3f3f;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        double tmp = (sum + mid) / n / 2;
        auto it = lower_bound(a.begin(), a.end(), tmp);
        if (distance(a.begin(), it) > n / 2)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    ll tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

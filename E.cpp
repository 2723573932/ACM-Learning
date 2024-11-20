#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    ll sum = 0, ans = 0;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    vector<ll> lst;
    for (int i = 0; i < n; i++)
    {
        sum += min(a[i], b[i]);
    }
    if (sum)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {

            if (a[i] != 0)
            {
                a[i] += c[i];
                c[i] = 0;
                ll tmp = min(a[i], b[i]);
                ans += a[i];
                a[i] -= tmp;
                sum += tmp;
            }
            else if (b[i] >= 1)
            {
                ll tmp = min(b[i], c[i] + 1) - 1;
                ans += c[i];
                c[i] -= tmp;
                sum += tmp;
            }
            else
            {
                lst.push_back(c[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i])
                a[i] += c[i];
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout << "\n";
        cout << accumulate(a.begin(), a.end(), 0ll);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] + c[i] + sum << " ";
    }
    cout << "\n";
    sort(lst.begin(), lst.end(), greater<ll>());
    for (ll i = 0; i < min<ll>(lst.size(), sum); i++)
    {
        ans += lst[i];
    }
    cout << ans;
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

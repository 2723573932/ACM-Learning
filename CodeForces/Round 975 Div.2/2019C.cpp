#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll maxn = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        maxn = max(maxn, x);
        sum += x;
    }
    if (sum + k >= n * maxn)
    {
        cout << n << '\n';
        return;
    }
    ll s;
    for (s = (sum+k) / maxn; s >= 1; s--)
    {
        if(sum+k>=maxn*s&&(sum+k)/s*s>=sum)
        {
            cout << s << '\n';
            return;
        }
    }
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

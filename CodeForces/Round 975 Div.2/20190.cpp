#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll a, b;
    a = b = 0;
    ll ax = 0, bx = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if (i & 1)
        {
            a++;
            ax = max(ax, x);
        }
        else
        {
            b++;
            bx = max(bx, x);
        }
    }
    cout << max(a+ax, b+bx) << '\n';
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

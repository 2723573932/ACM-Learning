#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e5 + 10;
void solve()
{
    int n, m;
    cin >> n >> m;
    ll maxn = -1;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        maxn = max(maxn, x);
    }
    while (m--)
    {
        char op;
        ll l, r;
        cin >> op >> l >> r;
        if (op == '+')
        {
            if (maxn <= r && maxn >= l)
                maxn++;
        }
        else
        {
            if (maxn <= r && maxn >= l)
                maxn--;
        }
        cout << maxn << ' ';
    }
    cout << '\n';
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

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, ans = 0;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int t = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            ans += t;
            break;
        }
        if (a[i] != a[i + 1])
        {
            ans++;
            i-=1;
            t = 1;
        }
        else
        {
            t++;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

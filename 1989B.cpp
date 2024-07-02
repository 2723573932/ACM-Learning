#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int x = 0, y = 0;
    int ans = 0;
    y = find(b.begin(), b.end(), a[0]) - b.begin();
    ans += y;
    while (x != a.size() && y != b.size())
    {
        if (a[x] == b[y])
        {
            y++;
        }
        x++;
    }
    ans = a.size() + b.size() - y;
    x = y = 0;
    while (x != a.size() && y != b.size())
    {
        if (a[x] == b[y])
        {
            y++;
        }
        x++;
    }
    ans = min(ans, (int)(a.size() + b.size() - y));
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

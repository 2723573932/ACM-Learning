#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int la = a.size(), lb = b.size();
    int ans = 0;
    for (int i = 0; i < lb; i++)
    {
        int x = 0, y = i;
        while (x < la && y < lb)
        {
            if (a[x] == b[y])
            {
                x++;
                y++;
            }
            else
            {
                x++;
            }
        }
        ans = max(ans, y - i);
    }
    cout << la + lb - ans << '\n';
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

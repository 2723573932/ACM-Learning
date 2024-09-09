#include <bits/stdc++.h>
using namespace std;

int mp[600][600];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            if (x == 'c')
                mp[i][j] = 1;
            else if (x == 'p')
                mp[i][j] = 2;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 1 && mp[i][j + 1] == 1 && mp[i + 1][j] == 2 && mp[i + 1][j + 1] == 1)
            {
                ans++;
            }
        }
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

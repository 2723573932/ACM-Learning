#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mp(4, vector<int>(2e5 + 7));
void solve()
{
    
    int n;
    cin >> n;
    mp[1][n+1]=mp[2][n+1]=0;
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            if (x == '.')
                mp[i][j] = 1;
            else
                mp[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= n; j++)
        {
            if (!mp[i - 1][j - 1] && !mp[i - 1][j] && !mp[i - 1][j + 1] && mp[i][j - 1] && mp[i][j + 1] && !mp[i + 1][j - 1] && mp[i + 1][j] && !mp[i + 1][j + 1])
                ans++;
            else if (!mp[i - 1][j - 1] && mp[i - 1][j] && !mp[i - 1][j + 1] && mp[i][j - 1] && mp[i][j + 1] && !mp[i + 1][j - 1] && !mp[i + 1][j] && !mp[i + 1][j + 1])
                ans++;
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

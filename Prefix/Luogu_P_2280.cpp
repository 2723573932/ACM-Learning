#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
int mp[N][N];
int prefix[N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        int x, y, v;
        cin >> x >> y >> v;
        mp[x + 1][y + 1] += v;
    }
    for (int i = 1; i <= 5e3+1; i++)
    {
        for (int j = 1; j <= 5e3+1; j++)
        {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mp[i][j];
        }
    }
    int ans = 0;
    for (int i = m; i <= 5e3+1; i++)
    {
        for (int j = m; j <= 5e3+1; j++)
        {
            ans = max(ans, prefix[i][j] - prefix[i - m][j] - prefix[i][j - m] + prefix[i - m][j - m]);
        }
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

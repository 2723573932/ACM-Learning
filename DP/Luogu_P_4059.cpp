#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<char, int> mp = {{'A', 0}, {'T', 1}, {'G', 2}, {'C', 3}};
int d[4][4];
ll dp[3001][3001][3];
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> d[i][j];
    ll a, b;
    cin >> a >> b;
    s1 = ' ' + s1, s2 = ' ' + s2;
    
    for(int i=max(n,m);i>=1;i--)
    {
        dp[0][i][0]=dp[i][0][0]=dp[0][i][2]=dp[i][0][1]=INT_MIN;
        dp[0][i][1]=dp[i][0][2]=-a-b*(i-1);
    }
    dp[0][0][1]=dp[0][0][2]=INT_MIN;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j][1] = max({dp[i][j - 1][0] - a, dp[i][j - 1][1] - b, dp[i][j - 1][2] - a});
            dp[i][j][2] = max({dp[i - 1][j][0] - a, dp[i - 1][j][1] - a, dp[i - 1][j][2] - b});
            dp[i][j][0] = max({dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]}) + d[mp[s1[i]]][mp[s2[j]]];
        }
    cout<<max({dp[n][m][0],dp[n][m][1],dp[n][m][2]})<<endl;
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

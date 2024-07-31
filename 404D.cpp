#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll dp[(int)1e6 + 7][3];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    dp[0][0] = dp[0][1]  = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            dp[i][0] = dp[i - 1][0] % mod;
        }
        else if (s[i] == '1')
        {
            dp[i][0] = dp[i - 1][2] % mod;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
        }
        else if (s[i] == '2')
        {
            dp[i][1] = dp[i - 1][2] % mod;
        }
        else if (s[i] == '*')
        {
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
        }
        else
        {
            dp[i][0] = (dp[i - 1][2] + dp[i - 1][0]) % mod;
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % mod;
            dp[i][2] = (dp[i - 1][2] + dp[i - 1][1]) % mod;
        }
    }
    cout << (dp[n][0] + dp[n][2]) % mod << "\n";
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

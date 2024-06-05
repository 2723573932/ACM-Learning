#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    string s;
    while (cin >> s && s != "0")
    {
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] > '0')
            {
                dp[i] = dp[i - 1];
            }
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
            {
                dp[i] += dp[i - 2];
            }
        }
        cout << dp[n] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
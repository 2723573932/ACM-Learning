#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int distinctSubseqII(string s)
    {
        int mod = 1e9 + 7;
        vector<int> last(26, -1);
        vector<int> dp(s.size() + 1);
        for (int i = 1; i <= s.size(); i++)
        {
            if (last[s[i - 1] - 'a'] == -1)
                dp[i] = (2LL * dp[i - 1] + 1) % mod;
            else
                dp[i] = (2LL * dp[i - 1] - dp[last[s[i - 1] - 'a'] - 1]) % mod;
            last[s[i - 1] - 'a'] = i;
        }
        return (dp.back()+mod)%mod;
    }
};
void solve()
{
    string s;
    cin >> s;
    Solution ob;
    cout << ob.distinctSubseqII(s) << "\n";
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

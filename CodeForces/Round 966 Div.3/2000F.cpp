#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1e9;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1, inf);
    dp[0] = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        vector<int> me(k + 1, inf);
        int cnt = 0;
        me[0] = 0;
        while (cnt++ < k && (a > 0 || b > 0))
        {
            me[cnt] = me[cnt - 1] + a;
            b--;
            if (a > b)
                swap(a, b);
        }
        for (int i = k - 1; i >= 0; i--)
            for (int j = 1; i + j <= k; j++)
                dp[i + j] = min(dp[i + j], dp[i] + me[j]);
    }
    cout << (dp[k] == inf ? -1 : dp[k]) << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
/*

*/
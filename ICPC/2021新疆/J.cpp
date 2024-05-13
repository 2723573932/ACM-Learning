#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long dp[N + 7][2];
long long lst[N + 7];
void solve()
{
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        lst[x]++;
    }
    for (int i = 1; i <= N; i++)
    {
        if (i & 1)
        {
            dp[i][0] = 0;
            dp[i][1] = lst[i];
        }
        else
        {
            dp[i][0] = dp[i / 2][1];
            dp[i][1] = min(dp[i / 2][1], dp[i / 2][0]) + lst[i];
        }
    }
    for (int i = N; 2 * i > N; i--)
    {
        ans += min(dp[i][0], dp[i][1]);
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}

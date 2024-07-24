#include <bits/stdc++.h>
using namespace std;
int N = 1e6 + 5;
void solve()
{
    int n;
    cin >> n;
    vector<int> dp(N);
    dp[0] = 1;
    bool f=0;
    for (int t = 0; t < n; t++)
    {
        int x;
        cin >> x;
        x = abs(x);
        for (int i = N - 1; i >= x; i--)
        {
            if (dp[i - x])
            {
                dp[i]++;
            }
            if (dp[i] >= 2)
            {
                f=1;
            }
        }
    }
    if(f)cout<<"YES\n";
    else
    cout << "NO\n";
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

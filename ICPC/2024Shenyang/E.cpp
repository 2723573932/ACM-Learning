#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<ll>> dp(1 << 16, vector<ll>(17, 0x3f3f3f3f));
void init()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    b = min(2 * a, b);
    c = min(2 * a, c);
    d = min({2 * b, 2 * c, d});
    vector<ll> mp(16);
    mp[1] = mp[2] = mp[4] = mp[8] = a;
    mp[12] = mp[3] = b;
    mp[10] = mp[5] = c;
    mp[15] = d;
    mp[6] = mp[9] = min(b + c, 2 * a);
    mp[7] = mp[11] = mp[13] = mp[14] = min({b + a, c + a, d + a});
    mp[0] = min({a, b, c, d}) * 2;
    for(int i=0;i<16;i++)
    {
        dp[1<<i][i]=mp[i];
    }
    for (int i = 1; i < (1 << 16); i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (i >> j & 1)
            {
                for (int k = 0; k < 16; k++)
                {
                    if (i >> k & 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + mp[(j ^ k)]);
                    }
                }
            }
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int _ = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int tmp = a / 10 * 8 + a % 10 * 4 + b / 10 * 2 + b % 10;
        _ ^= 1 << ((15 ^ tmp));
    }
    ll ans = 0x3f3f3f3f3f3f;
    for (int i = 0; i < 16; i++)
    {
        if (_ >> i & 1)
        {
            // cout<<dp[_][i]<<' '<<i<<endl;
            ans = min(ans, dp[_][i]);
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    init();
    while (tt--)
        solve();
    return 0;
}
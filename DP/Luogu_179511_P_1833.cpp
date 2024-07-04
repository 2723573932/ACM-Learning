//混合背包
#include <bits/stdc++.h>
using namespace std;
int dp[1007];
struct Luogu_179511_P_1833
{
    int t, c, p;
};
void solve()
{
    int hh, mm, h, m, n;
    scanf("%d:%d %d:%d %d", &hh, &mm, &h, &m, &n);
    int tt = (h - hh) * 60 + m - mm;
    vector<Luogu_179511_P_1833> lst;
    for (int i = 0; i < n; i++)
    {
        int t, c, p;
        scanf("%d %d %d", &t, &c, &p);
        lst.push_back({t,c,p});
    }
    for (auto &i : lst)
    {
        if (i.p == 0)
        {
            for (int j = i.t; j <= tt; j++)
            {
                dp[j] = max(dp[j], dp[j - i.t] + i.c);
            }
        }
        else
        {
            for (int k = 1; k <= i.p; k++)
            {
                for (int j = tt; j >= i.t * k; j--)
                {
                    dp[j] = max(dp[j], dp[j - i.t] + i.c);
                }
            }
        }
    }
    cout << dp[tt];
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

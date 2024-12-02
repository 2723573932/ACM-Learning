#include <bits/stdc++.h>
using namespace std;
int ox[] = {-2, -1, 1, 2};
int oy[] = {-2, -1, 1, 2};
vector<vector<int>> dp(30, vector<int>(30, 0x3f3f3f3f));
void solve()
{
    dp[1][1] = 0;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    queue<array<int, 3>> que;
    que.push({0, 1, 1});
    while (!que.empty())
    {
        int i, x, y;
        i = que.front()[0];
        x = que.front()[1];
        y = que.front()[2];
        que.pop();
        for (auto dx : ox)
            for (auto dy : oy)
            {
                if (abs(dx * dy) > 1)
                    if (x + dx > 0 && x + dx < 30 && y + dy > 0 && y + dy < 30)
                        if (dp[x + dx][y + dy] > i + 1)
                        {
                            dp[x + dx][y + dy] = i + 1;
                            que.push({i + 1, x + dx, y + dy});
                        }
            }
    }
    cout<<dp[x1][y1]<<'\n'<<dp[x2][y2];
}
int main()
{
#if !local
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if local
    system("pause");
#endif
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mp(107, vector<int>(107, -1));
int n, m;
void dfs(int num)
{
    if(num>n*m)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<mp[i][j]<<" ";
            }
            cout<<'\n';
        }
        exit(0);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == -1)
            {
                if (abs(mp[i - 1][j] - num) != 1 && abs(mp[i + 1][j] - num) != 1 && abs(mp[i][j - 1] - num) != 1 && abs(mp[i][j + 1] - num) != 1)
                {
                    mp[i][j] = num;
                    dfs(num + 1);
                    mp[i][j] = -1;
                }
            }
        }
}
void solve()
{
    cin >> n >> m;
    dfs(1);
    cout<<"-1";
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

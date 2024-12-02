#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n + 2, vector<char>(m + 2, 0));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    function<bool(int, int)> dfs = [&](int x, int y) -> bool
    {
        if (!mp[x][y])
            return true;
        if (vis[x][y] == 2)
            return false;
        else if (vis[x][y] == 1)
            return true;
        vis[x][y] = 2;
        if (mp[x][y] == 'R')
        {
            if (dfs(x, y + 1))
            {
                vis[x][y] = 1;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (mp[x][y] == 'L')
        {
            if (dfs(x, y - 1))
            {
                vis[x][y] = 1;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (mp[x][y] == 'U')
        {
            if (dfs(x - 1, y))
            {
                vis[x][y] = 1;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (mp[x][y] == 'D')
        {
            if (dfs(x + 1, y))
            {
                vis[x][y] = 1;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(dfs(x,y+1)&&dfs(x,y-1)&&dfs(x-1,y)&&dfs(x+1,y))
            {
                vis[x][y]=1;
                return true;
            }
            else
            {
                return false;
            }
        }
    };
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!vis[i][j])
            {
                dfs(i,j);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vis[i][j]==2)ans++;
        }
    }
    cout<<ans<<'\n';
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

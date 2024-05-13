#include <bits/stdc++.h>
using namespace std;

void dfs(int xx, int yy, int x, int y, int k)
{
    if (k == 1)
        return;
    int t = k / 2;
    if (xx + t > x && yy + t > y)
    {
        cout << xx + t << " " << yy + t << " 1\n";
        dfs(xx, yy, x, y, t);
        dfs(xx, yy + t, xx + t - 1, yy + t, t);
        dfs(xx + t, yy, xx + t, yy + t - 1, t);
        dfs(xx + t, yy + t, xx + t, yy + t, t);
    }
    else if (xx + t > x)
    {
        cout << xx + t << " " << yy + t - 1 << " 2\n";
        dfs(xx, yy, xx + t - 1, yy + t - 1, t);
        dfs(xx, yy + y, x, y, t);
        dfs(xx + t, yy, xx + t, yy + t - 1, t);
        dfs(xx + t, yy + t, xx + t, yy + t, t);
    }
    else if (y < yy + t)
    {
        cout << xx + t - 1 << " " << yy + 1 << " 3\n";
        dfs(xx, yy, xx + t - 1, yy + t - 1, t);
        dfs(xx, yy + t, xx + t - 1, yy + t, t);
        dfs(xx + t, yy, x, y, t);
        dfs(xx + t, yy + t, xx + t, yy + t, t);
    }
    else
    {
        cout << xx + t - 1 << " " << yy + t - 1 << " 4\n";
        dfs(xx, yy, xx + t - 1, yy + t - 1, t);
        dfs(xx, yy + t, xx + t - 1, yy + t, t);
        dfs(xx + t, yy, xx + t, yy + t - 1, t);
        dfs(xx + t, yy + t, x, y, t);
    }
}
void solve()
{
    int k, x, y;
    cin >> k >> x >> y;
    dfs(1,1,x,y,(1<<k));
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

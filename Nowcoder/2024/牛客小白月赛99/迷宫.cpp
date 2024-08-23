#include <bits/stdc++.h>
using namespace std;
int mp[1005][1005];
void solve()
{
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            if (x == '#')
                mp[i][j] = 0;
            else if (x == 'S')
            {
                x1 = i;
                y1 = j;
                mp[i][j] = 1;
            }
            else if (x == 'E')
            {
                x2 = i;
                y2 = j;
                mp[i][j] = 1;
            }
            else
                mp[i][j] = 1;
        }
    }
    set<int> xs, ys, xe, ye;
    queue<pair<int, int>> que;
    que.emplace(x1, y1);
    while (!que.empty())
    {
        auto [x, y] = que.front();
        que.pop();
        if (mp[x][y] == 0)
            continue;
        xs.insert(x);
        ys.insert(y);
        xs.insert(x + 1);
        xs.insert(x - 1);
        ys.insert(y + 1);
        ys.insert(y - 1);
        mp[x][y] = 0;
        if (mp[x][y + 1])
        {
            que.emplace(x, y + 1);
        }
        if (mp[x][y - 1])
        {
            que.emplace(x, y - 1);
        }
        if (mp[x + 1][y])
        {
            que.emplace(x + 1, y);
        }
        if (mp[x - 1][y])
        {
            que.emplace(x - 1, y);
        }
    }
    if(mp[x2][y2]==0)
    {
        cout<<"YES\n";
        return;
    }
    que.emplace(x2, y2);
    while (!que.empty())
    {
        auto [x, y] = que.front();
        que.pop();
        if (mp[x][y] == 0)
            continue;
        xe.insert(x);
        ye.insert(y);
        mp[x][y] = 0;
        if (mp[x][y + 1])
        {
            que.emplace(x, y + 1);
        }
        if (mp[x][y - 1])
        {
            que.emplace(x, y - 1);
        }
        if (mp[x + 1][y])
        {
            que.emplace(x + 1, y);
        }
        if (mp[x - 1][y])
        {
            que.emplace(x - 1, y);
        }
    }
    vector<int> ans;
    set_intersection(xs.begin(), xs.end(), xe.begin(), xe.end(), back_insert_iterator(ans));
    set_intersection(ys.begin(), ys.end(), ye.begin(), ye.end(), back_insert_iterator(ans));
    if (ans.size())
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

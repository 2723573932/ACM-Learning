#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = ' ' + s;
    pair<int, int> p;
    vector<pair<int, int>> v(n + 1);
    vector<map<pair<int, int>, int>> mp(n + 1);
    mp[0][{0, 0}] = 1;
    for (int i = 1; i <= n; i++)
    {
        switch (s[i])
        {
        case 'R':
            p.first += 1;
            break;
        case 'L':
            p.first -= 1;
            break;
        case 'U':
            p.second += 1;
            break;
        case 'D':
            p.second -= 1;
            break;
        default:
            break;
        }
        v[i] = p;
        mp[i] = mp[i - 1];
        mp[i][p]++;
    }
    while (q--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if (l == r)
            if (mp[n][{x, y}])
            {
                cout << "YES\n";
                continue;
            }
        if (mp[l - 1][{x, y}])
        {
            cout << "YES\n";
            continue;
        }
        else if (mp[n][{x, y}] - mp[r][{x, y}])
        {
            cout << "YES\n";
            continue;
        }
        else
        {
            int nx = v[r].first + v[l - 1].first - x;
            int ny = v[r].second + v[l - 1].second - y;
            if (mp[r][{nx, ny}] - mp[l - 1][{nx, ny}])
            {
                cout << "YES\n";
                continue;
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
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

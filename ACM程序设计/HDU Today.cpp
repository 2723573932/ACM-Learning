#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 157;
int G[N][N];
void solve(const int n)
{
    memset(G, 0x3f3f3f3f, sizeof(G));
    map<string, int> mp;
    string a, b;
    string start, end;
    int cnt = 1;
    cin >> start >> end;
    mp[start] = cnt++;
    if (mp.count(end) == 0)
        mp[end] = cnt++;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> a >> b >> c;
        if (mp.count(a) == 0)
            mp[a] = cnt++;
        if (mp.count(b) == 0)
            mp[b] = cnt++;
        G[mp[b]][mp[a]] = G[mp[a]][mp[b]] = min(G[mp[a]][mp[b]], c);
    }
    for (int i = 1; i < cnt; i++)
        G[i][i] = 0;
    for (int k = 1; k < cnt; k++)
        for (int i = 1; i < cnt; i++)
            for (int j = 1; j < cnt; j++)
            {
                if (G[i][k] != 0x3f3f3f3f && G[k][j] != 0x3f3f3f3f)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
    if (G[mp[start]][mp[end]] == 0x3f3f3f3f)
        cout << "-1\n";
    else
        cout << G[mp[start]][mp[end]] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while (cin >> tt && tt != -1)
        solve(tt);
    return 0;
}

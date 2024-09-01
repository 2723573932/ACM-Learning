#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    s = '0' + s;
    vector<int> f(n + 1);
    vector<int> vis(n + 1);
    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        int pos = i;
        int tmp = 0;
        while (!vis[pos])
        {
            vis[pos] = 1;
            pos = a[pos];
            que.push(pos);
            tmp += (s[pos] == '0');
        }
        while (!que.empty())
        {
            f[que.front()] = tmp;
            que.pop();
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<f[i]<<' ';
    }
    cout<<'\n';
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

#include <bits/stdc++.h>
using namespace std;
int cal(vector<int> &a)
{
    int n = a.size();
    vector<pair<int, int>> pos(n);
    for (int i = 1; i < n; i++)
    {
        pos[i] = {a[i], i};
    }
    sort(pos.begin(), pos.end());
    vector<bool> vis(n, false);
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (vis[i] || pos[i].second == i)
        {
            continue;
        }
        int tmp = 0;
        int j = i;

        while (!vis[j])
        {
            vis[j] = true;
            j = pos[j].second;
            tmp++;
        }
        if (tmp > 1)
        {
            ans += (tmp - 1)/2;
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[a[i]] == i)
            swap(a[i], a[a[i]]);
    }
    ans=cal(a);
    cout << ans << '\n';
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

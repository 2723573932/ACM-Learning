#include <bits/stdc++.h>
using namespace std;
int calc(int n, vector<int> &a)
{
    int p = n + 1;
    for (int i = 1; i <= n; i++)
        if (a[i] > 0)
        {
            p = i;
            break;
        }
    int R = n, L = n, ans = 0;
    for (int i = 0; i < p; i++)
    {
        while (L >= i && a[L] >= -i)
            L--;
        L = max(L, i);
        while (R >= p && n - R - i < a[R])
            R--;
        ans = max(ans, R - L);
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = calc(n, a);
    for (int i = 1; i <= n; i++)
        a[i] *= -1;
    reverse(a.begin() + 1, a.end());
    ans = max(ans, calc(n,a));
    cout<<ans<<'\n';
}
int main()
{
#if !LOCaL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCaL
    system("pause");
#endif
    return 0;
}

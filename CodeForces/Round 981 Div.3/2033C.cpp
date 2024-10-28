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
    for (int i = 2; i <= n / 2; i++)
    {
        if (a[i - 1] == a[i])
            swap(a[i], a[n - i + 1]);
        else if(a[n-i+1]==a[n-i+2])
            swap(a[n-i+1],a[i]);
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] == a[i])
            ans++;
    }
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

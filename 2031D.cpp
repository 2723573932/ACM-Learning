#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), maxn(n);
    cin >> a[0];
    maxn[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        maxn[i] = max(maxn[i - 1], a[i]);
    }
    int minn = a.back();
    a[n - 1] = maxn[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (maxn[i] <= minn)
        {
            minn = min(minn, a[i]);
            a[i] = maxn[i];
        }
        else
        {
            minn = min(minn, a[i]);
            a[i] = a[i + 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
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

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long ans = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int tmp = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            tmp += ceil(log2(1.0 * a[i - 1] / a[i]));
        }
        else
        {
            tmp -= floor(log2(1.0 * a[i] / a[i - 1]));
        }
        tmp=max(0,tmp);
        ans += tmp;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

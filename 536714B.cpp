#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n), prefix(n+1);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i <= k; i++)
        prefix[i] = prefix[i - 1] + a[i-1];
    long long ans = 0x3f3f3f3f;
    long long maxn = n - (lower_bound(a.begin(), a.end(), m) - a.begin());
    for (int i = 0; i <= maxn; i++)
    {
        long long sum = 0;
        for (int j = 0; j <= i; j++)
            sum += prefix[k - j] + j * m;
        for (int j = 1; j <= n + i; j++)
        {
            if (j >= k)
                sum += prefix[k - i] + i * m;
            else if (j >= k - i)
                sum += prefix[k - i] + (j - k + i) * m;
            else
                sum += a[j];
        }
        ans = min(ans, sum);
    }
    cout<<ans<<'\n';
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

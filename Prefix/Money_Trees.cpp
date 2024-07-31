#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
vector<int> h(N, 1), a(N);
void solve()
{
    int n, k;
    cin >> n >> k;
    fill(h.begin(), h.end(), 1);
    fill(a.begin(), a.end(), 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    int ans = 0;
    int l, r;
    r = 1;
    l = 1;
    while (r <= n)
    {
        while (r <= n && a[r] - a[l - 1] <= k)
        {
            ans = max(ans, r - l + 1);
            if (h[r] % h[r + 1] != 0)
            {
                l = r;
                r++;
                break;
            }
            r++;
        }
        l++;
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

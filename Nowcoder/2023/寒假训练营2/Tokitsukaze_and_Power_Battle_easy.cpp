#include <bits/stdc++.h>
using namespace std;
// int a[10000000];
// long long sum[1000000];
// int c[1000000];
int a[12];
long long sum[12];
int c[12];
void solve()
{
    int n, q;
    cin >> n >> q;
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int op, x, y;
    while (q--)
    {
        cin >> op >> x >> y;
        if (op & 1)
        {
            c[x] = y - a[x];
            a[x] = y;
        }
        else
        {
            for (int i = y; i > x; i--)
            {
                if (2 * a[i-1] - a[i] < 0)
                {
                    y = i;
                    break;
                }
            }
            for (int i = 1; i <= n; i++)
            {
                c[i] += c[i - 1];
                sum[i] += c[i];
            }
            cout << -(sum[y] - 2 * sum[y - 1] + sum[x - 1]) << '\n';
            memset(c, 0, sizeof(c));
        }
    }
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

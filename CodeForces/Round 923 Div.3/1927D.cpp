#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int q;
    cin >> q;
    int l, r, f = 0;
    while (q--)
    {
        int i;
        f = 0;
        cin >> l >> r;
        for (i = l; i < r - r % 4; i += 4)
        {
            if (a[i] != a[i + 1])
            {
                f = 1;
                break;
            }
            if (a[i + 1] != a[i + 2])
            {
                f = 1;
                i+=1;
                break;
            }
            if (a[i + 2 != a[i + 3]])
            {
                f = 1;
                i+= 2;
                break;
            }
        }
        for (int v = r - r % 4; v < r; v++)
            if (a[v] != a[v + 1])
            {
                f = 1;
                i=v;
                break;
            }
        if (f == 1)
            cout << i << ' ' << i + 1 << '\n';
        else
            cout << "-1 -1\n";
    }
    cout << '\n';
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

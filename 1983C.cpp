#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    int a[n + 1], b[n + 1], c[n + 1];
    a[0] = b[0] = c[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    int tot = a[n];
    int la = 0, lb = 0, lc = 0;
    int ra = n, rb = n, rc = n;
    ra = lower_bound(a + 1, a + n + 1, (tot + 2) / 3) - a;
    rb = lower_bound(b + 1, b + n + 1, (tot + 2) / 3) - b;
    rc = lower_bound(c + 1, c + n + 1, (tot + 2) / 3) - c;
    for (int i = ra + 1; i <= n; i++)
    {
        if (b[i] - b[ra] >= (tot + 2) / 3 && c[n] - c[i] >= (tot + 2) / 3)
        {
            lb = ra + 1;
            rb = i;
            lc = i + 1;
            rc=n;
            break;
        }
        if (c[i] - c[ra] >= (tot + 2) / 3 && b[n] - b[i] >= (tot + 2) / 3)
        {
            lc = ra + 1;
            rc = i;
            lb = i + 1;
            rb=n;
            break;
        }
    }
    if (lb != 0 && lc != 0)
    {
        la=1;
        cout << la << ' ' << ra << ' ' << lb << ' ' << rb << ' ' << lc << ' ' << rc << '\n';
        return;
    }
    for (int i = rb + 1; i <= n; i++)
    {
        if (a[i] - a[rb] >= (tot + 2) / 3 && c[n] - c[i] >= (tot + 2) / 3)
        {
            la = rb + 1;
            ra = i;
            lc = i + 1;
            rc = n;
            break;
        }
        if (c[i] - c[rb] >= (tot + 2) / 3 && a[n] - a[i] >= (tot + 2) / 3)
        {
            lc = rb + 1;
            rc = i;
            la = i + 1;
            ra = n;
            break;
        }
    }
    if (la != 0  && lc != 0)
    {
        lb=1;
        cout << la << ' ' << ra << ' ' << lb << ' ' << rb << ' ' << lc << ' ' << rc << '\n';
        return;
    }
    for (int i = rc + 1; i <= n; i++)
    {
        if (a[i] - a[rc] >= (tot + 2) / 3 && b[n] - b[i] >= (tot + 2) / 3)
        {
            la = rc + 1;
            ra = i;
            lb = i + 1;
            rb = n;
            break;
        }
        if (b[i] - b[rc] >= (tot + 2) / 3 && a[n] - a[i] >= (tot + 2) / 3)
        {
            lb = rc + 1;
            rb = i;
            la = i + 1;
            ra = n;
            break;
        }
    }if (la != 0 && lb != 0)
    {
        lc=1;
        cout << la << ' ' << ra << ' ' << lb << ' ' << rb << ' ' << lc << ' ' << rc << '\n';
        return;
    }
    cout<<"-1\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin>>tt;
    while (tt--)
        solve();
    return 0;
}

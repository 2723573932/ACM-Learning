#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    int sum = 0, l = 0, r = 0;
    vector<int> lst(n + 1, y);
    for (int i = 1; i <= k; i++)
    {
        cin >> lst[i];
        if (lst[i] < y)
            l++;
        else
            r++;
        sum += lst[i];
    }
    if (lst[(n + 1) / 2] < y || sum + (n / 2 - l) + (n / 2 + 1 - r) * y > x)
    {
        cout << "-1";
        return;
    }
    else
    {
        if (r <= n / 2)
        {
            for (int i = 1; i <= (n / 2 - l); i++)
                cout << "1 ";
            for (int i = 1; i <= (n / 2 + 1 - r); i++)
                cout << y << ' ';
        }
        else
            for (int i = 1; i <= n - r; i++)
                cout << "1 ";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k, n, p, x, y;
    cin >> n >> k >> p >> x >> y;
    int lower, upper, sum;
    sum = lower = upper = 0;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        sum += a;
        if (a < y)
            lower++;
        else
        {
            upper++;
        }
    }
    if (upper > n / 2)
    {
        sum += n - k;
    }
    else
    {
        sum += (n / 2 + 1 - upper) * y + (n / 2 - lower);
    }
    if (lower > n / 2 || sum > x)
        cout << "-1\n";
    else
    {
        if (upper <= n / 2)
        {
            for (int i = 0; i < n / 2 + 1 - upper; i++)
                cout << y << " ";
            for (int i = 0; i < n / 2 - lower; i++)
                cout << "1 ";
        }
        else{
            for (int i = 0; i < n - k; i++)
                cout << "1 ";
        }
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

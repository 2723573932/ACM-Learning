#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    if (n == 2)
    {
        cout << "-1\n";
        return;
    }
    int mp[n][n];
    int x = 0, y = 0;
    for (x = 1; x < n; x++)
    {
        if (gcd(x, n) == 1)
            for (y = 1; y <= x; y++)
                if (gcd(y, n) == 1 && gcd(x + y, n) == 1 && gcd(x - y, n) == 1)
                    break;
        if (gcd(y, n) == 1 && gcd(x + y, n) == 1 && gcd(x - y, n) == 1)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[i][j] = (x*i+y*j) % n ;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mp[i][j] << " ";
        }
        cout << "\n";
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

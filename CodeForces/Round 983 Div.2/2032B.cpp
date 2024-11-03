#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == k && k == 1)
    {
        cout << "1\n1\n";
    }
    else if (k == 1 || k == n)
        cout << -1 << '\n';
    else
    {
        if (k & 1)
        {
            cout << "5\n";
            cout << "1 " << k - 1 << ' ' << k << ' ' << k + 1 << ' ' << k + 2 << '\n';
        }
        else
        {
            cout << "3\n";
            cout << "1 " << k << ' ' << k + 1 << '\n';
        }
    }
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

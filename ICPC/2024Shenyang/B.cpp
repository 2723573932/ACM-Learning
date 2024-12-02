#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (gcd(n, m) == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
        cout << (m * i + 1)%(n*m) << ' ';
    cout << '\n';
    for (int i = 0; i < m; i++)
        cout << (n * i + 1)%(n*m) << ' ';
    cout << '\n';
    
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

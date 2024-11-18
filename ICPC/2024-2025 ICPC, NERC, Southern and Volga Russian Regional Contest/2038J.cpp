#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    while (n--)
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'B')
        {
            if (sum < x)
            {
                cout << "YES\n";
                sum = 0;
            }
            else
            {
                cout << "NO\n";
                sum -= x;
            }
        }
        else
        {
            sum += x;
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
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

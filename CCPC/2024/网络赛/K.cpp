#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n>>k;
    if (n & 1 || k >= n)
    {
        cout << "Alice" << '\n';
        return;
    }
    else
    {
        int sum = 1;
        while (n % 2 == 0)
        {
            n /= 2;
            sum *= 2;
        }
        if (sum <= k)
        {
            cout << "Alice" << '\n';
        }
        else
        {
            cout << "Bob" << '\n';
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

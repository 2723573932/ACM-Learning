#include <bits/stdc++.h>
using namespace std;

void solve()
{
    char a, op, b;
    cin >> a >> op >> b;
    if (a == b)
    {
        cout << a << '=' << b << '\n';
    }
    else if (a > b)
    {
        cout << a << '>' << b << '\n';
    }
    else
    {
        cout << a << '<' << b << '\n';
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

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int lst[100];
    int n, x, cnt = 0;
    memset(lst, -1, sizeof(lst));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int i = 0; i < n; i++)
        {
            if (x == lst[i] + 1)
            {
                cout << char('a' + i);
                lst[i]++;
                break;
            }
        }
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

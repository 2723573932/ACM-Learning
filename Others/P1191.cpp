#include <bits/stdc++.h>
using namespace std;

int lst[200];
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            if (x == 'W')
            {
                lst[j]++;
            }
            else
                lst[j] = 0;
        }
        for (int j = 1; j <= n; j++)
        {
            if (lst[j] == 0)
                continue;
            int tmp = lst[j];
            for (int k = j; k <= n; k++)
            {
                if (lst[k] == 0)
                    break;
                tmp = min(tmp, lst[k]);
                ans += tmp;
            }
            
        }
    }
    cout << ans << '\n';
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

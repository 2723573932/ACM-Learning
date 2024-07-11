#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<int> lst(k);
    for (int i = 0; i < k; i++)
        cin >> lst[i];
    sort(lst.begin(), lst.end());
    int count = 0;
    auto it = lower_bound(lst.begin(), lst.end(), n);
    if (it == lst.end())
    {
        it--;
    }
    int ans = min(n - *(it - 1), n - *it);
    int tmp = ans;
    for (int i = 0; i < k;)
    {
        if (tmp == 0)
            break;
        if (lst[i] == 1)
        {
            i++;
            tmp--;
        }
        else if (tmp > lst[i])
        {
            tmp -= lst[i];
            ans += lst[i] - 1;
            i++;
        }
        else if (tmp == lst[i])
        {
            ans += lst[i] - 1;
            break;
        }
        else
        {
            ans += tmp;
            break;
        }
    }
    cout << ans << '\n';
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

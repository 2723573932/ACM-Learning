#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 4 == 0)
    {
        cout << "NO\n";
        return;
    }
    bitset<33> b(n);
    vector<int> ans(32);
    cout << "YES\n";
    b.set(32);
    bool f = 0;
    for (int i = 0; i < 32; i++)
    {
        
        if (b[i])
        {
            if (f)
                ans[i - 1] = 1;
            f = 1;
        }
        if (f)
            ans[i] = -1;
    }
    ans.back()=1;
    for (int i = 1; i <= 32; i++)
    {
        cout << ans[i - 1] << " ";
        if (i % 8 == 0)
            cout << '\n';
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

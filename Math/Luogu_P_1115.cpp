#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = -INT_MAX;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        tmp += x;
        ans = tmp>ans?tmp:ans;
        tmp=tmp>0?tmp:0;
    }
    cout << ans << '\n';
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

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int tmp = 0;
    int ans = 0;
    while (n--)
    {
        int a;
        cin >> a;
        if (a >= k)
            tmp += a;
        if(a==0&tmp>0)
            tmp--,ans++;
    }
    cout<<ans<<'\n';
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

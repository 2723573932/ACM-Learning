#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<'\n';
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
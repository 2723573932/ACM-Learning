#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans=0;
    if(a1>b1&&a2>=b2||a1>=b1&&a2>b2)
    {
        ans++;
    }
    if(a1>b2&&a2>=b1||a1>=b2&&a2>b1)
    {
        ans++;
    }
    cout<<ans*2<<'\n';
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

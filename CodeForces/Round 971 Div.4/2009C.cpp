#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, y, k;
    cin >> x >> y >> k;
    long long ans = 0;
    if(y>=x)ans=(y+k-1)/k*2;
    else{
        ans=((x+k-1)/k);
        if((ans-1)*k>=y)ans=ans*2-1;
        else ans=ans*2;
    }
    cout << ans << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    long long tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

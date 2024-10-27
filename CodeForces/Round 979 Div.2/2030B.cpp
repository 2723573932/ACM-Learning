#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    cout<<"1";
    while(--n)cout<<"0";
    cout<<'\n';
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

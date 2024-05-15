#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    if(d>=b&&c>=a&&c<=b||b>=d&&a>=c&&a<=d) cout<<"YES\n";
    else cout<<"NO\n";
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

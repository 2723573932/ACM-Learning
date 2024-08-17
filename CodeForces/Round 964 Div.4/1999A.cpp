#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int sum=0;
    while(n)    
    {
        sum+=n%10;
        n/=10;
    }
    cout<<sum<<'\n';
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

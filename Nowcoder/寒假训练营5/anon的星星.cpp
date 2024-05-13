#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x;
    cin>>n>>x;
    if((x+n)&1)
    cout<<-1;
    else cout<<(x+n)/2<<' '<<n-(x+n)/2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    //cin>>tt;
    while(tt--)solve();
    return 0;
}

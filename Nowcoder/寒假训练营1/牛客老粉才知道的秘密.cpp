#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    if(n%6==0)cout<<n/6<<'\n';
    else cout<<ceil(n/3)<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while(tt--)solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n,ans=0,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x!=1)
        ans++;
    }
    cout<<ans<<endl;
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

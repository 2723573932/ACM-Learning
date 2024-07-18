#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    ans+=a/50-2;
    if(b<33);
    else if(b<44)ans+=1;
    else ans+=2;
    if(c<33);
    else if(c<44)ans+=1;
    else ans+=2;
    cout<<ans<<endl;
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

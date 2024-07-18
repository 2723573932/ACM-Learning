#include<bits/stdc++.h>
using namespace std;

int mp[1000][1000];
void solve()
{
    int ans=0,m,n,k;
    cin>>m>>n>>k;
    while (k--)
    {
        int x,y;
        cin>>x>>y;
        ans+=4;
        mp[x][y]=1;
        if(mp[x+1][y]==1)
        {
            ans--;
        }
        if(mp[x-1][y]==1)
        {
            ans--;
        }
        if(mp[x][y+1]==1)
        {
            ans--;
        }
        if(mp[x][y-1]==1)
        {
            ans--;
        }
    }
    cout<<ans<<'\n';
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

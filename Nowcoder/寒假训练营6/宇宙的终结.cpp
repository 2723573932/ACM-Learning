#include<bits/stdc++.h>
using namespace std;
int lst[]={30,42,66,78,70};
void solve()
{
    int l,r;
    cin>>l>>r;
    for(auto i:lst)
    {
        if(i<=r&&i>=l)
        {
            cout<<i;
            return;
        }
    }
    cout<<"-1";
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

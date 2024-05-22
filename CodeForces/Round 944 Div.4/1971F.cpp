#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long r;
    cin>>r;
    long long ans=0;
    long long h=r;
    for(long long i=0;i<=r;i++)
    {
        while(i*i+h*h>=(r+1)*(r+1)&&h>0)
        {
            h--;
        }
        long long tmp=h;
        while(i*i+tmp*tmp>=(r)*(r)&&tmp>0)
        {
            tmp--;
            ans++;
        }
        
    }
    cout<<ans*4<<'\n';
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

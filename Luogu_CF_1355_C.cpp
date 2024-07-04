#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c,d;
    int ans=0;
    cin>>a>>b>>c>>d;
    for(int i=a;i<=b;i++)
    {
        for(int j=b;j<=c;j++)
        {
            for(int k=c;k<=d;k++)
            {
                if(i+j>k&&i-k<j&&j-k<i)
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

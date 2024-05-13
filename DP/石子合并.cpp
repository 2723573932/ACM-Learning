#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
void solve()
{
    int n;
    cin >> n;
    int lst[n+1];
    memset(dp,0x3f3f,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        dp[i][i]=0;
    }
    lst[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>lst[i];
        lst[i]+=lst[i-1];
    }
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            for(int k=l;k<r;k++)
            {
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]+lst[r]-lst[l-1]);
            }
        }
    }
    cout<<dp[1][n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}

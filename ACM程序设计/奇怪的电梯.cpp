#include<bits/stdc++.h>
using namespace std;

int dp[1005];
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int lst[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>lst[i];
    }
    dp[a]=1;
    queue<pair<int,int>> q;
    q.push({a,1});
    auto ans=q.front();
    while(dp[b]==0)
    {
        if(q.empty())
        {
            cout<<-1;
            return;
        }
        ans=q.front();
        q.pop();
        if(ans.first+lst[ans.first]<=n && dp[ans.first+lst[ans.first]]==0)
        {
            dp[ans.first+lst[ans.first]]+=dp[ans.first];
            q.push({ans.first+lst[ans.first],ans.second+1});
        }
        if(ans.first-lst[ans.first]>=1 && dp[ans.first-lst[ans.first]]==0)
        {
            dp[ans.first-lst[ans.first]]+=dp[ans.first];
            q.push({ans.first-lst[ans.first],ans.second+1});
        }
    }
    cout<<ans.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    // cin>>tt;
    while(tt--)solve();
    return 0;
}

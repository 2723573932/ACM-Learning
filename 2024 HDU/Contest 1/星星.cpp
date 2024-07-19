#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1007][5000];
void solve()
{
	int n,k;
	cin>>n>>k;
  for(int i = 0; i <= k; ++i) {
		dp[0][i] = 0x3f3f3f3f;
	}
	dp[0][0]=0;
	for(int i=1; i<=n; i++)
	{
		int a[5];
		for(int j=1; j<=4; j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=k;j++){
			dp[i][j]=dp[i-1][j];
			for(int l=1;l<5;l++){
				dp[i][j]=min(dp[i][j],dp[i-1][j-l]+a[l]);
			}
		}
		
	}
	cout<<dp[n][k]<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	cin>>tt;
	while(tt--)
		solve();
	return 0;
}

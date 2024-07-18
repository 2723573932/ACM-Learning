#include<bits/stdc++.h>
using namespace std;
#define int long long
int mp[4][(int)1e6+7],f[4][(int)1e6+7];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1; i<=2; i++)
		for(int j=1; j<=n; j++)
		{
			char x;
			cin>>x;
			mp[i][j]=(x=='R'?1:0);
		}
	int ans=0;
	mp[1][0]=mp[2][0]=1;
	for(int j=1; j<=n; j++)
	{
		if(mp[1][j])
			f[1][j]=f[1][j-1]+1;
		if(mp[2][j])
			f[2][j]=f[2][j-1]+1;
		if(f[1][j]>f[2][j]&&f[2][j]!=0)
			f[2][j]=f[1][j]+1;
		else if(f[2][j]>f[1][j]&&f[1][j]!=0)
			f[1][j]=f[2][j]+1;
		if(f[1][j]==f[2][j]&&f[1][j]!=0)
		{
			f[1][j]++;
			f[2][j]++;
		}
		ans=max(ans,max(f[1][j],f[2][j]));
	}
	cout<<(ans==0?0:ans-1);
	return 0;
}
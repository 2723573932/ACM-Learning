#include <bits/stdc++.h>
using namespace std;
#define N 105
#define T 1005
int dp[N][T];//dp[i][j]:在前i个鱼塘中钓鱼，消耗时间j，可以钓到鱼的最大数量。
int fish[N], de[N], f[N][T], t[N], st[N], mxTime[N];
int n, endT, mxFish;
int main()
{
	cin >> n;//n:鱼塘数量 
	for(int i = 1; i <= n; ++i)
		cin >> fish[i];//fish[i]:第1分钟第i鱼塘可以钓到的鱼的数量
	for(int i = 1; i <= n; ++i)
		cin >> de[i];//dec[i]:每过一分钟鱼可以钓到的鱼减少的数量
	for(int i = 1; i <= n; ++i)
		for(int j = 1; fish[i] > 0; ++j)
		{
			f[i][j] = f[i][j-1] + fish[i];//f[i][j]:在第i鱼塘钓鱼j分钟能钓到的鱼
			fish[i] -= de[i];
			mxTime[i] = j;//mxTime[i]:在第i鱼塘能钓到鱼的最大时间（超过这一时间就钓不到鱼了） 
		}
	for(int i = 1; i <= n-1; ++i)
	{
		cin >> t[i];//t[i]:从第i鱼塘走到第i+1鱼塘的时间
		st[i+1] = st[i] + t[i];//st[i]:从第1鱼塘走到第i鱼塘的时间 
	}
	cin >> endT;//endT:截止时间 
	for(int i = 1; i <= n; ++i)//i:鱼塘号 
		for(int j = 1; j <= endT; ++j)//j:消耗时间 
			for(int k = 0; k <= mxTime[i] && k <= j-st[i]; ++k)//k：在第j鱼塘钓鱼k分钟 
				dp[i][j] = max(dp[i][j], dp[i-1][j-t[i-1]-k] + f[i][k]);
	for(int i = 1; i <= n; ++i)
		mxFish = max(mxFish, dp[i][endT]);
	cout << mxFish;
	return 0;
}

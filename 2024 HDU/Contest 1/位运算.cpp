//https://acm.hdu.edu.cn/contest/problems?cid=1124
#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
	int n,k;
	cin>>n>>k;
	vector<bool> lst;
	while(n>0) {
		lst.push_back(n%2);
		n>>=1;
	}
	int a=0;
	for(const auto &i:lst)
		if(i)a++;
	int ans=pow(12,a)*pow(4,k-a);
	cout<<ans<<'\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	cin>>tt;
	while(tt--)
		solve();
	return 0;
}

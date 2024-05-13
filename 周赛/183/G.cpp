#include<bits/stdc++.h>
using namespace std;

void solve() {
	map<char,int> mp;
	int n;
	cin>>n;
	vector<int> lst(n+1);
	char x;
	for(int i=0; i<n; i++) {
		cin>>x;
		mp[x]++;
	}
	int cnt=0;
	for(auto i:mp) {
		lst[cnt++]=i.second;
	}
	int ans=*max_element(lst.begin(),lst.end());
	if(ans>n/2)cout<<2*ans-n<<'\n';
	else cout<<n%2<<'\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	cin>>tt;
	while(tt--)
		solve();
}
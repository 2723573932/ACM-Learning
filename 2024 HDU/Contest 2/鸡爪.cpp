#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	cin>>tt;
	while(tt--)
	{
		int n;
		cin>>n;
		int tmp=n/3;
		int ans=0;
		if(tmp<=1)
		{
			for(int i=2;i<=n+1;i++)
			cout<<1<<" "<<i<<'\n';		
		}
		else if(tmp==2)
		{
			for(int i=2;i<=n-1;i++)
			{
				cout<<1<<" "<<i<<'\n';
			}
			cout<<"2 3\n2 4\n"; 
		}
		else if(tmp==3)
		{
			for(int i=2;i<=n-3;i++)
			{
				cout<<1<<" "<<i<<'\n';
			}
			cout<<"2 3\n2 4\n2 5\n3 4\n";
		}
		else{
			for(int i=2;i<=tmp+3+n-tmp*3;i++)
			{
				cout<<1<<' '<<i<<'\n';
			}
			for(int i=3;i<=tmp+2;i++)
			{
				cout<<2<<' '<<i<<'\n'; 
			} 
			for(int i=4;i<=tmp+1;i++)
			{
				cout<<3<<' '<<i<<'\n';
			}
		}
	}
	return 0;
}

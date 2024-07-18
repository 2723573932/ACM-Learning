#include <bits/stdc++.h>
using namespace std;
void solve()
{
	long long n;
	cin >> n;
	deque<int> lst;
	while (n > 0)
	{
		lst.push_front(n % 2);
		n >>=1;
	}

//	for(auto x : lst) cout << x << " " ;

	for (auto it = lst.rbegin(); it != lst.rend(); it++)
	{
		if (*it == 1)
		{
			*it = 0;
			break;
		}
	}
	long long ans=0;
//	for(const auto &i:lst)
//	cout<<i<<' ';
//	cout<<'\n';
	for(int i=lst.size()-1;i>=0;i--)
	{
		ans+= ((long long)1<<(lst.size()-i-1))*lst[i];
	}
	if(ans==0)ans=-1;
//	else ans*=2;
	cout<< ans <<'\n';
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
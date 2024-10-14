#include <bits/stdc++.h>
using namespace std;
vector<bool> is_prime(2000001, 1);
vector<int> primes;
 
void init() {
	is_prime[1] = 0;
	for(int i = 2; i <= 2000000; ++i) {
		if(is_prime[i]) {
			primes.push_back(i);
		}
		for(auto x : primes) {
			if(i * x > 2000000 ) break;
			is_prime[i * x] = 0;
			if(i % x == 0) break;
		}
	}
}
void solve()
{
    init();
    int n;
    cin>>n;
    int tmp=n;
    map<int,int> mp;
    for(const auto &i:primes)
    {
        while(tmp%i==0)
        {
            mp[i]++;
            tmp/=i;
        }
    }
    cout<<mp.size()<<'\n';
    for(const auto &[k,w]:mp)
    {
        cout<<"1 "<<n/k<<'\n';
    }
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

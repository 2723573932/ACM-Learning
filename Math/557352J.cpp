#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n,x,f=1;
	cin>>n>>x;
	if(x&1) {
		vector<int> a(n);
		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a.begin(),a.end());
		for(int i=0; i<n-1; i++)
			if(a[i]+a[i+1]==x) {
				f=0;
				if(a.back()!=a[i+1]) {
					a.insert(a.begin()+i+1,a[n-1]);
					f=1;
					a.pop_back();
					break;
				}
				if(a[0]!=a[i]) {
					a.insert(a.begin()+i+1,a[0]);
					f=1;
					a.erase(a.begin());
					break;
				}
			}
		if(f)for(const auto &i:a)cout<<i<<' ';
		else cout<<"*";
	} else {
		multiset<int> st;
		for(int i=0;i<n;i++) {
			int tmp;
			cin>>tmp;
			st.insert(tmp);
		}
		if(st.count(x/2)<2) {
			vector<int> a(st.begin(),st.end());
			for(int i=0; i<n-1; i++)
				if(a[i]+a[i+1]==x) {
					f=0;
					if(a.back()!=a[i+1]) {
						a.insert(a.begin()+i+1,a[n-1]);
						f=1;
						a.pop_back();
						break;
					}
					if(a[0]!=a[i]) {
						a.insert(a.begin()+i+1,a[0]);
						f=1;
						a.erase(a.begin());
						break;
					}
				}
			if(f)for(const auto &i:a)cout<<i<<' ';
			else cout<<"*";
		} else {
            deque<int> ans;
			int cnt=st.count(x/2);
			st.erase(x/2);
			if(st.size()<cnt-1)cout<<"*";
			else {
				ans.push_back(x/2);
				while(--cnt) {
					ans.push_back(*st.begin());
                    ans.push_back(x/2);
					st.erase(st.begin());
				}
				for(auto &i:st)
					if(i<x/2)
                    ans.push_front(i);
                    else ans.push_back(i);
                for(const auto &i:ans)cout<<i<<' ';
			}
		}
	}

	return 0;
}

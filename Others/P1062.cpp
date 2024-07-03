#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int k,n;
    cin>>k>>n;
    queue<int> st;
    for(int i=1;n>0;i++)
    {
        st.push(n%2);
        n/=2;
    }
    int ans=0;
    int i=0;
    while(!st.empty())
    {
        ans+=st.front()*pow(k,i++);
        st.pop();
    }
    cout<<ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> a[n+7];
    while(k--)
    {
        int l,r;
        cin>>l>>r;
        a[l].push_back(r+1);
    }
    int ans1,ans2,maxn=0,minn=0x3f3f3f3f;
    unordered_multiset<int> st;
    for(int i=1;i<d;i++)
    {
        st.insert(a[i].begin(),a[i].end());
    }
    for(int i=d;i<=n;i++)
    {
        st.insert(a[i].begin(),a[i].end());
        st.erase(i-d+1);
        if(st.size()>maxn)
        {
            maxn=st.size();
            ans1=i-d+1;
        }
        if(st.size()<minn)
        {
            minn=st.size();
            ans2=i-d+1;
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

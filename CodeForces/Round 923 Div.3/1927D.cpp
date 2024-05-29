#include <bits/stdc++.h>
using namespace std;
long long lst[(int)1e6+7];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>lst[i];
    }
    vector<int> ans;
    for(int i=1;i<n;i++)
    {
        if(lst[i]!=lst[i+1])
        ans.push_back(i);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        auto it=lower_bound(ans.begin(),ans.end(),l);
        if(it==ans.end())
        {
            cout<<"-1 -1\n";
            continue;
        }
        int tmp=*it;
        if(tmp>=l&&tmp+1<=r)
        cout<<tmp<<' '<<tmp+1<<'\n';
        else cout<<"-1 -1\n";
    }
    cout<<'\n';

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

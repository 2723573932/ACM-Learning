#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int c = INT_MAX;
    while (k--)
    {
        int x;
        cin >> x;
        c = min(c, x);
    }
    vector<tuple<int,int,string>> lst(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        string b;
        cin >> a >> b;
        lst[i] = {a, i, b};
    }
    sort(lst.begin(), lst.end(),greater<tuple<int,int,string>>());
    vector<int> ans(n);
    unordered_map<string, int> mp;
    int sum=0;
    for(const auto &[w,i,name]:lst)
    {
        if(mp[name]<c)
        {
            ans[i]=sum+1;
            mp[name]++;
            sum++;
        }
        else
        {
            ans[i]=sum;
        }
    }
    for(const auto &x:ans)
    {
        cout<<x<<'\n';
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

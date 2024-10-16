#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    int ans=0;
    for(int i=0;i<min(n,m);i++)
    {
        if(s[i]==t[i])
            ans++;
        else
            break;
    }
    if(ans)
    cout<<n+m-ans+1<<'\n';
    else
    cout<<n+m<<'\n';
    
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

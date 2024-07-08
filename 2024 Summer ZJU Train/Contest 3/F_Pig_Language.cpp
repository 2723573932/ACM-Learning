#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int ans=0;
    for(int i=s.length()-1;i>=2;i--)
    {
        if(s[i]=='y'&&s[i-1]=='x'&&s[i-2]=='y')
        {
            ans++;
            s[i-2]='x';
        }
    }   
    if(s[0]=='x'&&s[1]=='y')
        ans++;
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

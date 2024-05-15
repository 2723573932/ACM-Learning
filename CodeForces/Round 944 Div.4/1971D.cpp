#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    if(is_sorted(s.begin(),s.end()))
    {
        cout<<1<<'\n';
        return;
    }
    int count=1;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]!=s[i+1]) count++;
    }
    if(count<=2)cout<<count<<'\n';
    else cout<<count-1<<'\n';
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

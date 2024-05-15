#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            swap(s[i],s[i+1]);
            cout<<"YES\n"<<s<<'\n';
            return;
        }
    }    
    cout<<"NO\n";
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

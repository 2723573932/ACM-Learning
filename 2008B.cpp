#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int m = int(sqrt(n));
    if (m * m != n)
    {
        cout << "No\n";
        return;
    }
    int pos=0;
    if(s.substr(0,m).find('0')!=string::npos)
    {
        cout<<"No\n";
        return;
    }
    if(s.substr(n-m,m).find('0')!=string::npos)
    {
        cout<<"No\n";
        return;
    }
    for(int i=1;i<m-1;i++)
    {
        auto tmp=s.substr(i*m,m);
        if(tmp[0]!='1'||tmp[m-1]!='1')
        {
            cout<<"No\n";
            return;
        }
        if(tmp.find('1',1)!=m-1)
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c : s)
    {
        mp[c]++;
        if(mp[c] ==3)
        {
            if(c=='T')cout<<"T1";
            else cout<<"DRX";
            return;
        }
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

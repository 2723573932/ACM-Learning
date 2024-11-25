#include <bits/stdc++.h>
using namespace std;
const string patten="You are right, but \"Sao Lei (Winmine)\" is a game whose Chinese name contains two characters while English name contains seven.";
void solve()
{
    string s;
    getline(cin,s);
    if(s.substr(0,19)==patten.substr(0,19))
    cout<<"AI\n";
    else
    cout<<"Human\n";
}
int main()
{
#if !LOCAL
    // ios::sync_with_stdio(0);
    // cin.tie(0);
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

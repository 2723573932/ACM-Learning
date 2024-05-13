#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s >> s;
    if (s.find("B") != string::npos)
        cout << s.rfind("B") - s.find("B") +1<< '\n';
    else
        cout << "0\n";
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

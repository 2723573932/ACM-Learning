#include <bits/stdc++.h>
using namespace std;

char trans(const char &c)
{
    if (c == 'A' || c == 'B' || c == 'C')
        return '2';
    if (c == 'D' || c == 'E' || c == 'F')
        return '3';
    if (c == 'G' || c == 'H' || c == 'I')
        return '4';
    if (c == 'J' || c == 'K' || c == 'L')
        return '5';
    if (c == 'M' || c == 'N' || c == 'O')
        return '6';
    if (c == 'P' || c == 'R' || c == 'S')
        return '7';
    if (c == 'T' || c == 'U' || c == 'V')
        return '8';
    if (c == 'W' || c == 'X' || c == 'Y')
        return '9';
    return '0';
}
void solve()
{
    map<string, int> mp;
    int n;
    cin >> n;
    while (n--)
    {
        string x;
        cin >> x;
        while (x.find('-') != string::npos)
        {
            x.erase(x.find('-'), 1);
        }
        for (auto &i : x)
        {
            if (isdigit(i))
                continue;
            else
                i = trans(i);
        }
        x.insert(x.begin() + 3, '-');
        mp[x]++;
    }
    int f = 1;
    for (const auto &i : mp)
    {
        if (i.second > 1)
        {
            f = 0;
            cout << i.first << ' ' << i.second << '\n';
        }
    }
    if(f)cout<<"No duplicates.";
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

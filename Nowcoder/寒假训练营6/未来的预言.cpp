#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    int x;
    scanf("BO%d",&x);
    cin >> b;
    int r, p;
    r = p = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == 'R')
            r++;
        else
            p++;
        if (r > x / 2)
        {
            cout << "kou!\n"
                 << i + 1;
            return;
        }
        else if (p > x / 2)
        {
            cout << "yukari!\n"
                 << i + 1;
            return;
        }
    }
    cout<<"to be continued.\n"<<b.size();
}
int main()
{
    //ios::sync_with_stdio(0);
   // cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}

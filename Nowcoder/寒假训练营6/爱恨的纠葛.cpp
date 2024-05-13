#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, p, minx = INT_MAX, pp;

    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        if(it==a.end())it--;
        if (abs(*it - b[i]) < minx)
        {
            minx = abs(*it - b[i]);
            pp = it - a.begin();
            p = i;
        }
        if (abs(*--it - b[i]) < minx)
        {
            minx = abs(*it - b[i]);
            pp = it - a.begin();
            p = i;
        }
    }
    n = a[p];
    a[p] = a[pp];
    a[pp] = n;
    for (auto i : a)
        cout << i << ' ';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}

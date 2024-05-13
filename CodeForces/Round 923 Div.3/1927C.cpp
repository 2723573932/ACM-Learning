#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k, x;
    cin >> n >> m >> k;
    set<int> a, b, sum;
    vector<int> uni;
    while (n--)
    {
        cin >> x;
        if (x > k)
            continue;
        a.insert(x);
        sum.insert(x);
    }
    while (m--)
    {
        cin >> x;
        if (x > k)
            continue;
        b.insert(x);
        sum.insert(x);
    }
    if (sum.size() != k||a.size()<k/2||b.size()<k/2)
    {
        cout << "NO\n";
        return;
    }
    else cout<<"YES\n";
    
    
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

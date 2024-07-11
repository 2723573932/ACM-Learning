#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (is_sorted(a.begin(), a.end(),less<int>()) || is_sorted(a.begin(), a.end(), greater<int>()))
    {
        cout << 0 << '\n';
        return;
    }
    int pos = 0;
    while (a[pos] == 0)
        pos++;
    cout << 2 * n << '\n';
    for (int i = 0; i < n; i++)
        cout << pos+1 << ' ';
    for (int i = n - 1; i >= 0; i--)
        cout << i+1 << ' ';
    cout<<'\n';
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

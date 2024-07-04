#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    if (find(a.begin(), a.end(), 0) != a.end())
    {
        cout << "YES\n";
        return;
    }
    map<int, int> mp1,mp2;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            mp1[abs(a[i] +a[j])]++;
            mp2[abs(a[i] - a[j])]++;
            if (mp1[abs(a[i] + a[j])] > 1||mp2[abs(a[i] - a[j])] > 1)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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

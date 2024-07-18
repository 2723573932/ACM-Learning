#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.first > b.first;
}
void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> lst(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> lst[i].first >> lst[i].second;
        m += lst[i].second;
    }
    sort(lst.begin(), lst.end(), cmp);
    for (auto i : lst)
    {
        if (m < i.first)
        {
            m -= i.second;
        }
    }
    cout << m << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

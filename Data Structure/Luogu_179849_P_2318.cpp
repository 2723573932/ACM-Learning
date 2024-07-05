#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, ans = 0;
    cin >> n >> m;
    unordered_map<long long, pair<long long, long long>> mp;                                                                        
    priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<>> pq;
    for (int i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        if (mp.count(x))
        {
            mp[x].first++;
            ans++;
            pq.push({mp[x].first, {i, x}});
        }
        else
        {
            if (mp.size() < n)
            {
                mp[x] = {1, i};
                pq.push({1, {i, x}});
            }
            else
            {
                while (!pq.empty() && mp[pq.top().second.second].first != pq.top().first)
                {
                    pq.pop();
                }
                auto it = pq.top();
                pq.pop();
                mp.erase(it.second.second);
                mp[x] = {1, i};
                pq.push({1, {i,x}});
            }
        }
    }
    cout << ans;
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

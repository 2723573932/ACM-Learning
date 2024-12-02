#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> h(n), v(n), ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> v[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        while (!pq.empty())
        {
            int hh, vv;
            tie(hh, vv) = pq.top();
            if (hh < h[i])
            {
                ans[i] += vv;
                pq.pop();
            }
            else
            {
                break;
            }
        }
        if (h[i + 1] > h[i])
            ans[i + 1] += v[i];
        else
        {
            pq.push({h[i], v[i]});
        }
    }
    while (!pq.empty())
    {
        int hh, vv;
        tie(hh, vv) = pq.top();
        if (hh < h[n - 1])
        {
            ans[n - 1] += vv;
        }
        pq.pop();
    }
    for (int i = n-1; i >0; i--)
    {
        while (!pq.empty())
        {
            int hh, vv;
            tie(hh, vv) = pq.top();
            if (hh < h[i])
            {
                ans[i] += vv;
                pq.pop();
            }
            else
            {
                break;
            }
        }
        if (h[i] < h[i-1])
            ans[i-1] += v[i];
        else
        {
            pq.push({h[i], v[i]});
        }
    }
    while (!pq.empty())
    {
        int hh, vv;
        tie(hh, vv) = pq.top();
        if (hh < h[0])
        {
            ans[0] += vv;
        }
        pq.pop();
    }
    cout<<*max_element(ans.begin(),ans.end());
}
int main()
{
#if !local
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if local
    system("pause");
#endif
    return 0;
}
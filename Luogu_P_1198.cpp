#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long m, d;
    deque<long long> q;
    cin >> m >> d;
    long long t = 0;
    while (m--)
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == 'A')
        {
            q.push_back((x + t) % d);
        }
        else
        {
            t = *max_element(q.end() - x, q.end());
            cout << t << '\n';
        }
    }
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

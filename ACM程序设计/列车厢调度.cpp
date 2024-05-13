#include <bits/stdc++.h>
using namespace std;

void solve()
{
    stack<int> stk;
    stk.push(NULL);
    queue<string> ans;
    string a, b;
    cin >> a >> b;
    int cur = 0;
    for (auto i : b)
    {
        if (stk.top() == i)
        {
            stk.pop();
            ans.push("3->2");
            continue;
        }
        while (cur < a.size())
        {
            if (a[cur] == i)
            {
                ans.push("1->2");
                cur++;
                break;
            }
            else
            {
                stk.push(a[cur++]);
                ans.push("1->3");
            }
        }
    }
    if (stk.top()==NULL)
    {
        while (!ans.empty())
        {
            cout << ans.front() << '\n';
            ans.pop();
        }
        
    }else
        cout<<"Are you kidding me?";
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

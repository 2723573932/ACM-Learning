#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    getline(cin, s);
    stack<char> stk;
    stk.push('1');
    int f=1,cnt1=0,cnt2=0;
    for (char c : s)
    {
        if(c=='('||c=='['||c=='{')
        {
            stk.push(c);
            cnt1++;
        }
        else if(c==')')
        {
            if(stk.top()=='(')
            {
                stk.pop();
            }
            else
            {
                f=0;
            }
            cnt2++;
        }
        else if(c==']')
        {
            if(stk.top()=='[')
            {
                stk.pop();
            }
            else
            {
                f=0;
            }
            cnt2++;
        }
        else if(c=='}')
        {
            if(stk.top()=='{')
            {
                stk.pop();
            }
            else
            {
                f=0;
            }
            cnt2++;
        }

    }
    cout<<cnt1<<' '<<cnt2<<'\n';
    if(f&&stk.top()=='1')cout<<"YES\n";
    else cout<<"NO\n";

}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}

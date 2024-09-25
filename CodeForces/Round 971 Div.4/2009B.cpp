#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    stack<int> st;
    while(n--)
    {
        string s;
        cin>>s;
        st.push(s.find('#')+1);
    }
    while(st.size())
    {
        cout<<st.top()<<' ';
        st.pop();
    }
    cout<<'\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

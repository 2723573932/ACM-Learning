#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "Yes\n";
        return;
    }
    multiset<long long> st;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        st.insert(x);
    }
    int tmp=st.count(1);
    st.erase(1);
    if (st.size()%2==1||(st.size()%2==0&&tmp%2==1))
        cout << "Yes\n";
    else
        cout << "No\n";
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

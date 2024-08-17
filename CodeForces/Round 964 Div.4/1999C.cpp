#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s, m;
    cin >> n >> s >> m;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        st.insert({l, r});
    }
    st.insert({m,m});
    auto it = st.begin();
    int t=0;
    while(it!=st.end())
    {
        auto [l,r]=*it;
        if(l-t>=s){
            cout<<"YES\n";
            return;
        }
        t=r;
        it++;
    }
    cout<<"NO\n";
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

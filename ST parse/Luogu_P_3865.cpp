#include <bits/stdc++.h>
using namespace std;
class ST
{
public:
    int n;
    vector<int> a;
    vector<vector<int>> st;
    ST(vector<int> &a) : a(a)
    {
        n = a.size();
        st.resize(n, vector<int>(__lg(n) + 1));
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; i + (1 << j) - 1 < n; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    int query(int l, int r)
    {
        int k = __lg(r - l + 1);
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    ST st(a);
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<st.query(l-1,r-1)<<'\n';
    }
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}

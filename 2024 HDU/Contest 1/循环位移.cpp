#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
vector<ull> p(1048576);
constexpr ull base = 131, mod = 1e9 + 7;
void ini()
{
    p[0] = 1;
    for (int i = 1; i < 1048576; i++)
        p[i] = p[i - 1] * base;
}
void solve()
{
    string a, b;
    cin >> a >> b;
    int ans = 0;
    ull lena = a.size(), lenb = b.size();
    vector<ull> hasha(2 * lena + 1), hashb(lenb + 1);
    a = a + a;
    for (int i = 0; i < 2 * lena; i++)
    {
        hasha[i + 1] = hasha[i] * base + a[i];
    }
    auto geta = [&](int l, int r)
    { return hasha[r] - hasha[l] * p[r - l]; };
    for (int i = 0; i < lenb; i++)
    {
        hashb[i + 1] = hashb[i] * base + b[i];
    }
    auto getb = [&](int l, int r)
    { return hashb[r] - hashb[l] * p[r - l]; };
    unordered_set<ull> st;
    for (int i = 0; i < lena; i++)
        st.insert(geta(i, i + lena));
    for (int i = 0; i <= lenb-lena; i++)
    {
        if (st.count(getb(i, i + lena)))
            ans++;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    ini();
    while (tt--)
        solve();
    return 0;
}

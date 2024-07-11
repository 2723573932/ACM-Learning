#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int maxn = a * b * c;
    for (int i = 0; i <= 5; i++)
        for (int j = 0; j + i <= 5; j++)
            for (int k = 0; k + i + j <= 5; k++)
            maxn=max(maxn,(a+i)*(b+j)*(c+k));
    cout<<maxn<<'\n';
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

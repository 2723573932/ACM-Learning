#include <bits/stdc++.h>
using namespace std;
// pi+i=2*(pi & i)+pi ^ i
int vis[(int)1e6];
int lst[(int)1e6];
void solve()
{
    int n;
    cin >> n;
    int tmp = n;
    int k = 0;
    while (tmp /= 2)
        k++;
    for (int i = n - 1; i >= 0; i--)
    {

        lst[i] = (1 << (k+1)) - 1 - i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << lst[i] << ' ';
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

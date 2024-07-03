#include <bits/stdc++.h>
using namespace std;

long long lst[(int)1e6 + 3];
void solve()
{
    long long n, f;
    cin >> n >> f;
    for (long long i = 1; i <= n; i++)
    {
        cin >> lst[i];
    }
    while (f--)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            long long l, r, k;
            cin >> l >> r >> k;
            for (int i = l; i <= r; i++)
                lst[i] += k;
            break;
        }
        case 2:
        {
            long long k;
            cin >> k;
            lst[1] += k;
            break;
        }
        case 3:
        {
            long long k;
            cin >> k;
            lst[1] -= k;
            break;
        }
        case 4:
        {
            long long l, r;
            cin >> l >> r;
            long long tmp=0;
            for(int i=l;i<=r;i++)
            tmp+=lst[i];
            cout<<tmp<<'\n';
            break;
        }
        case 5:
        {
            cout<<lst[1]<<'\n';
            break;
        }
        default:
            break;
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

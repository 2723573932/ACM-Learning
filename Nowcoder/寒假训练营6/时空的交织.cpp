#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;
    long long a[n], b[m], a1[n], b1[m], a2[n], b2[m];
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        a1[i] = a2[i] = a[i];
        if (i != 0)
        {
            if (a1[i - 1] > 0)
                a1[i] = a1[i - 1] + a[i];
            if (a2[i - 1] < 0)
                a2[i] = a2[i - 1] + a[i];
        }
    }
    for (long long i = 0; i < m; i++)
    {
        cin >> b[i];
        b1[i] = b2[i] = b[i];
        if (i != 0)
        {
            if (b1[i - 1] > 0)
                b1[i] = b1[i - 1] + b[i];
            if (b2[i - 1] < 0)
                b2[i] = b2[i - 1] + b[i];
        }
    }
    cout<<max(max(*max_element(a1,a1+n)* *max_element(b1,b1+m),*min_element(a2,a2+n)* *min_element(b2,b2+m)),max(*min_element(a,a+n)* *max_element(b,b+m),*max_element(a,a+n)* *min_element(b,b+m)));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}

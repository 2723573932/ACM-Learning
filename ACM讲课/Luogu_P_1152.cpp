#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
        b.push_back(abs(a[i] - a[i - 1]));
    sort(b.begin(), b.end());
    for(int i=0;i<b.size();i++)
    {
        if(b[i]!=i+1)
        {
            cout<<"Not jolly\n";
            return;
        }
    }
    cout<<"Jolly\n";
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

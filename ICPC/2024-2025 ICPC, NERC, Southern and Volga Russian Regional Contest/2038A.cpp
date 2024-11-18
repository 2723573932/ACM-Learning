#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), ans(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = a[i] / b[i];
        sum += ans[i];
    }
    if (sum >= k)
    {
        for (int i = 0; i < n; i++)
        {
            if(sum>k)
            {
                if(sum-ans[i]>=k)
                {
                    sum-=ans[i];
                    ans[i]=0;
                }
                else{
                    ans[i]-=sum-k;
                    break;
                }
            }else{
                break;
            }
        }
        for (auto i : ans)
            cout << i << ' ';
    }
    else
    {
        for(int i=0;i<n;i++)cout<<"0 ";
        return;
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

#include <bits/stdc++.h>
using namespace std;
constexpr long long maxn = 1e9;
void solve()
{
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long l = 0, r = maxn;

    while (l < r)
    {
        set<int> st;
        long long mid = l + (r - l) / 2;
        // Check if mid is a valid answer
        auto it = st.lower_bound(mid);
        bool isValid = true; // Assume mid is valid
        // Perform necessary checks or calculations using mid
        // Update isValid accordingly
        
        if (isValid)
        {
            // mid is a valid answer, so update the lower bound
            l = mid + 1;
        }
        else
        {
            // mid is not a valid answer, so update the upper bound
            r = mid;
        }
    }

    // At this point, l will be the smallest valid answer
    // Do further processing or output the result as needed
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

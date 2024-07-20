
#include <bits/stdc++.h>
using namespace std;
#define int long long
// 使用归并排序的方法计算逆序对
int mergeSortAndCount(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    int count = mergeSortAndCount(arr, l, mid) + mergeSortAndCount(arr, mid + 1, r);
    vector<int> temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += mid - i + 1; // 计算逆序对
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (int i = l, k = 0; i <= r; ++i, ++k)
        arr[i] = temp[k];
    return count;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        st.insert(b[i]);
    }
    if (st.size() != n)
    {
        cout << "NO\n";
        return;
    }

    int a1 = mergeSortAndCount(a, 0, n - 1);
    int a2 = mergeSortAndCount(b, 0, n - 1);
    if ((a1 % 2) == (a2 % 2))
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
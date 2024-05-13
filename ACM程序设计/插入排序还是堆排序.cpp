#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    ;
    cin >> n;
    vector<int> lst(n), ans(n);
    for (auto &i : lst)
        cin >> i;
    for (auto &i : ans)
        cin >> i;
    if (is_sorted_until(ans.begin(), ans.end(),less<int>()) -ans.begin()>is_heap_until(ans.rbegin(),ans.rend())-ans.rbegin())
    {
        cout << "Insertion Sort" << endl;
        int i = 0;
        while (i < n - 1 && ans[i] <= ans[i + 1])
            i++;
        i++;
        sort(ans.begin(), ans.begin() + i + 1);
    }
    else
    {
        cout << "Heap Sort" << endl;
        int i = n - 1;
        while (i > 0 && ans[i] >= ans[0])
            i--;
        make_heap(ans.begin(), ans.begin() + i + 1);
        pop_heap(ans.begin(), ans.begin() + i + 1);
    }
    for (auto it=ans.begin();it!=ans.end();it++)
        if (it == ans.begin())
            cout << *it;
        else
            cout << ' '<<*it;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}

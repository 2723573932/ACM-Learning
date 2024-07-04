#include <bits/stdc++.h>
using namespace std;

class BinaryIndexedTree
{
private:
    vector<int> tree;
    vector<int> sum1;
    vector<int> sum2;
    int n;

public:
    BinaryIndexedTree(int n) : tree(n + 1), sum1(n + 1), sum2(n + 1),n(n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> tree[i];
            sum1[i] = sum1[i - 1] + tree[i];
            sum2[i] = sum2[i - 1] + tree[i] * i;
        }
    }
};
void solve()
{
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

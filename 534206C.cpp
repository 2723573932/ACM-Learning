#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> mp(n, vector<int>(n, 0));
    if (n & 1)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                mp[i][j] = (i + j) % n + 1;
            }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - 1; j++)
            {
                mp[i][j] = (i + j) % (n - 1) + 1;
            }
        for(int i=0;i<n;i++)
        {
            if()
            mp[i][n-1]=mp[n-1][(i+1)%n]=mp[i][(i+1)%n];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mp[i][j] << " ";
        }
        cout << '\n';
    }
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

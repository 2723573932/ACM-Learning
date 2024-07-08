#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    cout << 6 << '\n';
    // if (n == 2)
    // {
    //     cout << "1 2\n 1 3\n 1 4\n 2 3\n 2 4\n 3 4\n ";
    //     return;
    // }
    if (n & 1)
    {
        string a, b, c, d;
        for (int i = 6; i < 2 * n; i++)
        {
            if ((i - 6) / ((2 * n - 6) / 4) == 0)
                a += to_string(1 + i) + " ";
            else if ((i - 6) / ((2 * n - 6) / 4) == 1)
                b += to_string(i + 1) + " ";
            else if ((i - 6) / ((2 * n - 6) / 4) == 2)
                c += to_string(i + 1) + " ";
            else
                d += to_string(i + 1) + " ";
        }
        cout << "1 2 3 " + a + b + "\n"
             << "1 4 5 " + a + c + "\n"
             << "1 3 6 " + b + d + "\n"
             << "2 4 6 " + a + d + "\n"
             << "2 5 6 " + c + d + "\n"
             << "3 4 5 " + b + c + "\n";
        return;
    }
    else
    {
        string a, b, c, d;
        for (int i = 0; i < 2 * n; i++)
        {
            if (i / (n / 2) == 0)
                a += to_string(i + 1) + " ";
            else if (i / (n / 2) == 1)
                b += to_string(1 + i) + " ";
            else if (i / (n / 2) == 2)
                c += to_string(i + 1) + " ";
            else
                d += to_string(i + 1) + " ";
        }
        cout << a + b << "\n"
             << a + c << "\n"
             << b + d << "\n"
             << a + d << "\n"
             << c + d << "\n"
             << b + c << "\n";
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

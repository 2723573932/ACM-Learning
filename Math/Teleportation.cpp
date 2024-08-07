#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ui = unsigned __int128;
void print(__int128 n)
{
    if (n == 0)
    {
        cout << "0";
        return;
    }
    string result = "";
    while (n > 0)
    {
        int digit = n % 10;
        result = to_string(digit) + result;
        n /= 10;
    }
    cout << result;
}
void solve()
{
    ull x, y;
    cin >> x >> y;
    ui a = x, b = y;
    deque<ui> va = {a}, vb = {b};
    ull cnt = 0;
    while (a >= 2)
    {
        while (a % 2 == 0)
            cnt++, a >>= 1;
        if (a < 2)
            break;
        if ((a - 1) % 4 == 0 && cnt)
        {
            a >>= 2;
            va.push_back((ui(1) << cnt) * 4 * a * (4 * a + 1));
            va.push_back((ui(1) << cnt) * 4 * a * (4 * a - 1));
            cnt += 2;
            va.push_back((ui(1) << cnt) * a);
        }
        else if ((a - 3) % 4 == 0 && cnt)
        {
            a >>= 2;
            va.push_back((ui(1) << cnt) * (4 * a + 2) * (4 * a + 3));
            va.push_back((ui(1) << cnt) * (4 * a + 3) * (4 * a + 4));
            cnt += 2;
            va.push_back((ui(1) << cnt) * (a + 1));
            a++;
        }
        else
        {
            a >>= 1;
            cnt++;
            va.push_back((ui(1) << cnt) * a * (2 * a + 1));
            va.push_back((ui(1) << cnt) * (a + 1) * (2 * a + 1));
            va.push_back((ui(1) << cnt) * (a + 1));
            a++;
        }
    }
    cnt = 0;
    while (b >= 2)
    {
        while (b % 2 == 0)
            cnt++, b >>= 1;
        if (b < 2)
            break;
        if ((b - 1) % 4 == 0 && cnt)
        {
            b >>= 2;
            vb.push_front((ui(1) << cnt) * 4 * b * (4 * b + 1));
            vb.push_front((ui(1) << cnt) * 4 * b * (4 * b - 1));
            cnt += 2;
            vb.push_front((ui(1) << cnt) * b);
        }
        else if ((b - 3) % 4 == 0 && cnt)
        {
            b >>= 2;
            vb.push_front((ui(1) << cnt) * (4 * b + 2) * (4 * b + 3));
            vb.push_front((ui(1) << cnt) * (4 * b + 3) * (4 * b + 4));
            cnt += 2;
            vb.push_front((ui(1) << cnt) * (b + 1));
            b++;
        }
        else
        {
            b >>= 1;
            cnt++;
            vb.push_front((ui(1) << cnt) * b * (2 * b + 1));
            vb.push_front((ui(1) << cnt) * (b + 1) * (2 * b + 1));
            vb.push_front((ui(1) << cnt) * (b + 1));
            b++;
        }
    }
    if (va.back() < vb[0])
    {
        ui t = vb[0] / va.back();
        va.push_back(va.back() * 3);
        vb.push_front(vb[0] * 3);
        while (t >>= 1)
            va.push_back(va.back() * 2);
    }
    else if (va.back() > vb[0])
    {
        ui t = va.back() / vb[0];
        va.push_back(va.back() * 3);
        vb.push_front(vb[0] * 3);
        while (t >>= 1)
            vb.push_front(vb[0] * 2);
    }
    else
    {
        va.pop_back();
    }
    cout << va.size() + vb.size() << '\n';
    for (auto &i : va)
    {
        print(i);
        cout << ' ';
    }
    for (auto &i : vb)
    {
        print(i);
        cout << ' ';
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("C:\\Users\\acm\\Desktop\\F-Teleportation\\1.in ", "r", stdin);
    // freopen("C:\\Users\\acm\\Desktop\\out.out", "w", stdout);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

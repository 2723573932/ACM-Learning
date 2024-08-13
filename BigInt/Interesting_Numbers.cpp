/*
#include <bits/stdc++.h>
using namespace std;
using bi = unsigned __int128;
using ll = long long;
bi (string s)
{
    bi tmp = 0;
    for (const auto &i : s)
    {
        tmp = tmp * 10 + i - '0';
    }
    return tmp;
}
bi sq(bi tmp)
{
    bi l = 0, r = tmp;
    while (l < r)
    {
        bi mid = (l + r) / 2;
        if (mid * mid < tmp)
            l = mid + 1;
        else
            r = mid;
    }
    if (l * l > tmp)
        l--;
    return l;
}
bi qpow(bi a, bi b)
{
    bi ret = 1;
    while (b)
    {
        if (b & 1)
            ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}
void print(bi tmp)
{
    string s;
    do
    {
        char x = tmp % 10 + '0';
        s = x + s;
        tmp /= 10;
    } while (tmp);
    cout << s;
}
void solve()
{
    int n;
    bi ans = 0;
    cin >> n;
    string l, r;
    cin >> l >> r;
    bi l1 = (l.substr(0, n / 2));
    bi l2 = (l.substr(n / 2));
    bi r1 = (r.substr(0, n / 2));
    bi r2 = (r.substr(n / 2));

    bi st = sq(l1);
    bi ed = sq(r1);

    if (st * st < l1)
        st++;
    if (ed * ed > r1)
        ed--;
    bi a = ed - st + 1;
    if (st * st == l1)
        a--;
    if (ed * ed == r1)
        a--;
    //	cout<<(ll)a<<'\n';
    bi b = sq(qpow(10, n / 2)-1) + 1;
    ans = a * b;
    //	cout<<ans<<'\n';
    if (st * st == l1)
    {
        bi tmp = sq(l2);
        if (tmp * tmp < l2)
            tmp++;
        ans += b - tmp;
    }
    if (ed * ed == r1)
    {
        bi tmp = sq(r2);
        if (tmp * tmp > r2)
            tmp--;
        ans += tmp + 1;
    }
    print(ans);
    return;
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
int128大法好
*/
#include <bits/stdc++.h>
using namespace std;
class BigInt
{
public:
    vector<int> num;
    BigInt()
    {
        num.push_back(0);
    }
    BigInt(int x)
    {
        num.clear();
        while (x)
        {
            num.push_back(x % 10);
            x /= 10;
        }
    }
    BigInt(string s)
    {
        stringstream ss;
        ss << s;
        ss >> *this;
        while (num.back() == 0 && num.size() > 1)
            num.pop_back();
    }
    BigInt operator+(const BigInt &b)
    {
        BigInt res;
        int carry = 0;
        for (int i = 0; i < max(num.size(), b.num.size()) || carry; i++)
        {
            if (i == res.num.size())
                res.num.push_back(0);
            res.num[i] += carry + (i < num.size() ? num[i] : 0) + (i < b.num.size() ? b.num[i] : 0);
            carry = res.num[i] >= 10;
            if (carry)
                res.num[i] -= 10;
        }
        return res;
    }
    BigInt operator-(const BigInt &b)
    {
        BigInt res;
        res.num.resize(num.size());
        for (int i = 0, carry = 0; i < num.size(); i++)
        {
            res.num[i] = num[i] - carry - (i < b.num.size() ? b.num[i] : 0);
            carry = res.num[i] < 0;
            if (carry)
                res.num[i] += 10;
        }
        while (res.num.size() > 1 && res.num.back() == 0)
            res.num.pop_back();
        return res;
    }
    BigInt operator*(const BigInt &b)
    {
        BigInt res;
        res.num.resize(num.size() + b.num.size());
        for (int i = 0; i < num.size(); i++)
            for (int j = 0, carry = 0; j < b.num.size() || carry; j++)
            {
                long long cur = res.num[i + j] + num[i] * 1ll * (j < b.num.size() ? b.num[j] : 0) + carry;
                res.num[i + j] = cur % 10;
                carry = cur / 10;
            }
        while (res.num.size() > 1 && res.num.back() == 0)
            res.num.pop_back();
        return res;
    }
    BigInt operator/(const BigInt &b)
    {
        BigInt res, cur = 0;
        res.num.resize(num.size());
        for (int i = num.size() - 1; i >= 0; i--)
        {
            cur = cur * 10;
            cur.num[0] = num[i];
            while (!(cur < b))
            {
                cur = cur - b;
                res.num[i]++;
            }
        }
        while (res.num.size() > 1 && res.num.back() == 0)
            res.num.pop_back();
        return res;
    }
    BigInt operator%(const BigInt &b)
    {
        BigInt res = *this / b;
        return *this - res * b;
    }
    bool operator<(const BigInt &b) const
    {
        if (num.size() != b.num.size())
            return num.size() < b.num.size();
        for (int i = num.size() - 1; i >= 0; i--)
            if (num[i] != b.num[i])
                return num[i] < b.num[i];
        return false;
    }
    bool operator==(const BigInt &b) const
    {
        return num == b.num;
    }
    bool operator!=(const BigInt &b) const
    {
        return num != b.num;
    }
    bool operator>(const BigInt &b) const
    {
        return b < *this;
    };
    bool operator<=(const BigInt &b) const
    {
        return !(b < *this);
    }
    bool operator>=(const BigInt &b) const
    {
        return !(*this < b);
    }
    string to_string()
    {
        string res;
        for (int i = num.size() - 1; i >= 0; i--)
            res += char(num[i] + '0');
        return res;
    }
    friend ostream &operator<<(ostream &out, BigInt b)
    {
        out << b.to_string();
        return out;
    }
    friend istream &operator>>(istream &in, BigInt &b)
    {
        string s;
        in >> s;
        b.num.clear();
        for (int i = s.size() - 1; i >= 0; i--)
            b.num.push_back(s[i] - '0');
        return in;
    }

    BigInt sqrt()
    {
        BigInt l, r = *this;
        while (l < r)
        {
            BigInt mid = (l + r) / 2;
            if (mid * mid < *this)
                l = mid + 1;
            else
                r = mid;
        }
        if (l * l > *this)
            return l - 1;
        return l;
    }
    BigInt pow(int n)
    {
        BigInt ret = 1;
        BigInt x = *this;
        while (n)
        {
            if (n & 1)
                ret = ret * x;
            x = x * x;
            n >>= 1;
        }
        return ret;
    }
};

using bi = BigInt;
void solve()
{
    int n;
    bi ans = 0;
    cin >> n;
    string l, r;
    cin >> l >> r;
    bi l1 = (l.substr(0, n / 2));
    bi l2 = (l.substr(n / 2));
    bi r1 = (r.substr(0, n / 2));
    bi r2 = (r.substr(n / 2));

    bi st = l1.sqrt();
    bi ed = r1.sqrt();

    if (st * st < l1)
        st = st + 1;
    if (ed * ed > r1)
        ed = ed - 1;
    bi a = ed - st + 1;
    if (st * st == l1)
        a = a - 1;
    if (ed * ed == r1)
        a = a - 1;
    bi b = (BigInt(10).pow(n / 2) - 1).sqrt() + 1;
    ans = a * b;
    if (st * st == l1)
    {
        bi tmp = l2.sqrt();
        if (tmp * tmp < l2)
            tmp = tmp + 1;
        ans = ans + b - tmp;
    }
    if (ed * ed == r1)
    {
        bi tmp = (r2).sqrt();
        if (tmp * tmp > r2)
            tmp = tmp - 1;
        ans = ans + tmp + 1;
    }
    cout << ans << '\n';
    return;
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

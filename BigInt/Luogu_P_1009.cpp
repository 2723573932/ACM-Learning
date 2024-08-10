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
};
void solve()
{
    BigInt a(1), sum;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a = a * BigInt(i);
        sum = sum + a;
    }
    cout<<sum;
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

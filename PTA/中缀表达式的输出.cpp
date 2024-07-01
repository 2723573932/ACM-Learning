#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
map<string, int> map1;
string num1[maxn], num2[maxn]; 
struct node
{
    node *left;
    node *right;
    string data;
};
int fla[4]; 
string s1, s2;
char a;
int p1 = -1, p2 = -1, cnt1 = 1, cnt2 = 1;

node *tree(int l1, int r1, int l2, int r2)
{
    node *p1;
    fla[3] = 0; 
    if (l1 > r1 && l2 > r2)
    {
        return NULL;
    }
    string head = num1[l1];
    p1 = new node();
    p1->data = head;
    for (int i = l2; i <= r2; i++)
    {
        if (num2[i] == head)
        {
            p1->left = tree(l1 + 1, l1 + (i - l2), l2, i - 1);
            p1->right = tree(l1 + (i - l2) + 1, r1, i + 1, r2);
            fla[3] = 1;
        }
    }
    if (fla[3] == 0)
    {
        fla[2] = 1;
    }
    return p1;
}

void readd()
{
    int tmp;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == ' ')
        {
            for (int j = p1 + 1; j < i; j++)
            {
                num1[cnt1] += s1[j];
            }
            map1[num1[cnt1++]]++;
            p1 = i;
        }
    }
    if (s1[s1.size() - 1] != ' ')
    {
        for (int j = p1 + 1; j < s1.size(); j++)
        {
            num1[cnt1] += s1[j];
        }
        map1[num1[cnt1]]++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] == ' ')
        {
            for (int j = p2 + 1; j < i; j++)
            {
                num2[cnt2] += s2[j];
            }
            if (map1[num2[cnt2]] == 0)
            {
                fla[1] = 1;
            }
            map1[num2[cnt2++]]--;
            p2 = i;
        }
    }
    if (s2[s2.size() - 1] != ' ')
    {
        for (int j = p2 + 1; j < s2.size(); j++)
        {
            num2[cnt2] += s2[j];
        }
        if (map1[num2[cnt2]] == 0)
        {
            fla[1] = 1;
        }
        tmp = map1[num2[cnt2]];
        map1[num2[cnt2]]--;
    }
}

void pre(node *p)
{
    if (p == NULL)
    {
        return;
    }
    char a;
    a = p->data[0];
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
        cout << "(";
    }
    pre(p->left);
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
        cout << a;
    }
    else
    {
        cout << p->data;
    }
    pre(p->right);
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
        cout << ")";
    }
}

void solve()
{
    getline(cin, s1);
    getline(cin, s2);
    readd();
    if (cnt1 != cnt2)
    { //数量不相等 
        cout << "The number of pre-order elements is different from the number of in-order elements.";
        return;
    }
    if (fla[1])
    { //元素不相同 
        cout << "Inconsistent pre-order elements and in-order elements.";
        return;
    }
    node *head1;
    head1 = tree(1, cnt1, 1, cnt1);
    if (fla[2])
    {
        cout << "This binary tree is not exists.";
        return;
    }
    pre(head1->left);
    cout << num1[1][0];
    pre(head1->right);
}

int main()
{
    solve();
    return 0;
}
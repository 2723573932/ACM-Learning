#include <bits/stdc++.h>
using namespace std;

// Function to check if the given binary tree exists
int isBinaryTreeExists(const vector<string> &preOrder, const vector<string> &inOrder)
{
    unordered_map<char, int> preOrderMap;
    unordered_map<char, int> inOrderMap;

    // Creating a map for pre-order elements
    for (int i = 0; i < preOrder.size(); i++)
    {
        preOrderMap[preOrder[i][0]]++;
    }

    // Creating a map for in-order elements
    for (int i = 0; i < inOrder.size(); i++)
    {
        inOrderMap[inOrder[i][0]]++;
    }

    // Checking if the number of pre-order elements is different from the number of in-order elements
    if (preOrderMap.size() != inOrderMap.size())
    {
        return 1;
    }

    // Checking if the pre-order elements and in-order elements are consistent
    for (int i = 0; i < preOrder.size(); i++)
    {
        if (preOrder[i] != inOrder[i])
        {
            return 2;
        }
    }

    return 0;
}

// Function to convert the given binary tree into an expression
string convertToExpression(const vector<string> &preOrder, const vector<string> &inOrder)
{
    switch (isBinaryTreeExists(preOrder, inOrder))
    {
        case 1:
            return "The number of pre-order elements is different from the number of in-order elements.";
        case 2:
            return "Inconsistent pre-order elements and in-order elements.";
        default:
            break;
    }

    stack<string> st;

    for (int i = preOrder.size() - 1; i >= 0; i--)
    {
        if (isalpha(preOrder[i][0]))
        {
            st.push(string(1, preOrder[i][0]));
        }
        else
        {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            string expression = "(" + operand1 + preOrder[i] + operand2 + ")";
            st.push(expression);
        }
    }

    return st.top();
}
vector<string> split(const string &s, char delim)
{
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim))
    {
        tokens.push_back(item);
    }
    return tokens;
}
int main()
{
    string preOrder, inOrder;
    getline(cin, preOrder);
    getline(cin, inOrder);
    vector<string> preOrderElements = split(preOrder, ' ');
    vector<string> inOrderElements = split(inOrder, ' ');
    string expression = convertToExpression(preOrderElements, inOrderElements);
    cout << expression << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool isVal(string s) {
    stack<char> stk1;
    for (char ch : s) 
    {
        if (!stk1.empty() && ((ch == '0' && stk1.top() == '1') || (ch == '1' && stk1.top() == '0'))) 
        {
            stk1.pop();
        } else {
            stk1.push(ch);
        }
    }
    return stk1.empty();
}

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        string S;
        cin >> S;
        if (isVal(S)) 
        {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

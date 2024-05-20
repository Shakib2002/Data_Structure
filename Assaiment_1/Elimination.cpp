#include<bits/stdc++.h>
using namespace std;
bool empty_Elimination(const string& s) 
{
    stack<char> stk1;
    for (char ch : s) 
    {
        if (!stk1.empty() && stk1.top() == '0' && ch == '1') {
            stk1.pop();  
        } else 
        {
            stk1.push(ch);
        }
    }
    return stk1.empty();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        if (empty_Elimination(S)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

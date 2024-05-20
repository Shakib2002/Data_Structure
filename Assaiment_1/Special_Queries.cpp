#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int Q;
    cin >> Q;
    queue<string> line;
    vector<string> res1;
    
    for (int i = 0; i < Q; ++i) 
    {
        int com;
        cin >> com;
        if (com == 0) 
        {
            string name;
            cin >> name;
            line.push(name);
        } else if (com == 1) 
        {
            if (line.empty()) 
            {
                res1.push_back("Invalid");
            } else 
            {
                res1.push_back(line.front());
                line.pop();
            }
        }
    }
    
    for (const string &res : res1) 
    {
        cout << res << endl;
    }
    
    return 0;
}

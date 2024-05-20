#include<bits/stdc++.h>
using namespace std;
string stack_Queue_Same(
    int N, int M, 
    vector<int>& stackVal, 
    vector<int>& queueVal) 
    {
    if (N != M) 
    {
        return "NO";
    }
    
    stack<int> stackCon;
    queue<int> queueCon;
    
 
    for (int i = 0; i < N; ++i) 
    {
        stackCon.push(stackVal[i]);
    }
    
 
    for (int i = 0; i < M; ++i) {
        queueCon.push(queueVal[i]);
    }
    
 
    vector<int> rev_Stack_Val;
    while (!stackCon.empty()) {
        rev_Stack_Val.push_back(stackCon.top());
        stackCon.pop();
    }
    
 
    for (int i = 0; i < M; ++i) {
        if (rev_Stack_Val[i] != queueCon.front()) {
            return "NO";
        }
        queueCon.pop();
    }
    
    return "YES";
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> stackVal(N);
    vector<int> queueVal(M);
    
    for (int i = 0; i < N; ++i) {
        cin >> stackVal[i];
    }
    
    for (int i = 0; i < M; ++i) {
        cin >> queueVal[i];
    }
    
    cout << stack_Queue_Same(N, M, stackVal, queueVal) << endl;
    
    return 0;
}

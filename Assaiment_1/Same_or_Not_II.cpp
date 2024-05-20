#include<bits/stdc++.h>
using namespace std;
class MyStack 
{
private:
    vector<int> stack;
    int top;
public:
    MyStack(int size) 
    {
        stack.resize(size);
        top = -1;
    }
    
    void push(int value) 
    {
        stack[++top] = value;
    }
    
    int pop() 
    {
        return stack[top--];
    }
    
    bool isEmpty() 
    {
        return top == -1;
    }
};

class MyQueue 
{
private:
    vector<int> queue;
    int front, rear;
public:
    MyQueue(int size) 
    {
        queue.resize(size);
        front = 0;
        rear = 0;
    }
    
    void enqueue(int value) 
    {
        queue[rear++] = value;
    }
    
    int dequeue() 
    {
        return queue[front++];
    }
    
    bool isEmpty() 
    {
        return front == rear;
    }
};

string stack_Queue_Same(
    int N, int M, 
    vector<int>& stackVal, 
    vector<int>& queueVal) 
    {
    if (N != M) 
    {
        return "NO";
    }
    
    MyStack stack(N);
    MyQueue queue(M);
    
    for (int i = 0; i < N; ++i) 
    {
        stack.push(stackVal[i]);
    }
    
    for (int i = 0; i < M; ++i) 
    {
        queue.enqueue(queueVal[i]);
    }
    
    vector<int> rev_Stack_Val(N);
    for (int i = 0; i < N; ++i) 
    {
        rev_Stack_Val[i] = stack.pop();
    }
    
    for (int i = 0; i < M; ++i) 
    {
        if (rev_Stack_Val[i] != queue.dequeue()) 
        {
            return "NO";
        }
    }
    
    return "YES";
}

int main() 
{
    int N, M;
    cin >> N >> M;
    
    vector<int> stackVal(N);
    vector<int> queueVal(M);
    
    for (int i = 0; i < N; ++i) 
    {
        cin >> stackVal[i];
    }
    
    for (int i = 0; i < M; ++i) 
    {
        cin >> queueVal[i];
    }
    
    cout << stack_Queue_Same(N, M, stackVal, queueVal) << endl;
    
    return 0;
}

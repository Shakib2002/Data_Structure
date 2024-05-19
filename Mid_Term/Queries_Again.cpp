#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

 bool insert_At_Index(Node*& head, Node*& tail, int index, int val) {
    Node* newNode = new Node(val);
    if (index == 0) {
         if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return true;
    } else {
        Node* curr = head;
        for (int i = 0; i < index - 1 && curr; i++) {
            curr = curr->next;
        }
        if (!curr) {
             delete newNode;
            return false;
        } else {
            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next) {
                curr->next->prev = newNode;
            } else {
                tail = newNode;
            }
            curr->next = newNode;
            return true;
        }
    }
}

 void print_Left_To_Right(Node* head) {
    cout << "L -> ";
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

 void print_Right_To_Left(Node* tail) {
    cout << "R -> ";
    Node* curr = tail;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < Q; ++i) {
        int X, V;
        cin >> X >> V;
        
        if (insert_At_Index(head, tail, X, V)) {
            print_Left_To_Right(head);
            print_Right_To_Left(tail);
        } else {
            cout << "Invalid" << endl;
        }
    }
    
     while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

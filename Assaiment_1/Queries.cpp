#include <iostream>
using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void insertAtHead(ListNode* &head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode* &head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteAtIndex(ListNode* &head, int index) {
    if (head == nullptr)
        return;
    if (index == 0) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    ListNode* prev = nullptr;
    ListNode* current = head;
    int count = 0;
    while (current != nullptr && count < index) {
        prev = current;
        current = current->next;
        count++;
    }
    if (current == nullptr)
        return;  
    prev->next = current->next;
    delete current;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    ListNode* head = nullptr;

    while (Q--) {
        int X, V;
        cin >> X >> V;
        if (X == 0) {
            insertAtHead(head, V);
        } else if (X == 1) {
            insertAtTail(head, V);
        } else if (X == 2) {
            deleteAtIndex(head, V);
        }
        printList(head);
    }

 
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

#include <iostream>
#include <unordered_set>
using namespace std;

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void removeDuplicates(ListNode* head) {
    if (head == nullptr)
        return;
    
    unordered_set<int> seen;
    seen.insert(head->val);
    
    ListNode* current = head;
    while (current->next != nullptr) {
        if (seen.find(current->next->val) != seen.end()) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            seen.insert(current->next->val);
            current = current->next;
        }
    }
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
    int val;
    cin >> val; 

    ListNode* head = new ListNode(val);
    ListNode* current = head;

 
    while (cin >> val && val != -1) {
        current->next = new ListNode(val);
        current = current->next;
    }

 
    removeDuplicates(head);

 
    printList(head);

 
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

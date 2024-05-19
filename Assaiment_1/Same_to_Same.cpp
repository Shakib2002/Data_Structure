 #include <iostream>
using namespace std;

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool areListsEqual(ListNode* head1, ListNode* head2) {
    while (head1 && head2) {
        if (head1->val != head2->val)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
 
    return (head1 == nullptr && head2 == nullptr);
}

int main() {
    int val;
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;

 
    while (cin >> val && val != -1) {
        if (head1 == nullptr) {
            head1 = new ListNode(val);
        } else {
            ListNode* current = head1;
            while (current->next != nullptr)
                current = current->next;
            current->next = new ListNode(val);
        }
    }

 
    while (cin >> val && val != -1) {
        if (head2 == nullptr) {
            head2 = new ListNode(val);
        } else {
            ListNode* current = head2;
            while (current->next != nullptr)
                current = current->next;
            current->next = new ListNode(val);
        }
    }
 
    if (areListsEqual(head1, head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
 
    while (head1) {
        ListNode* temp = head1;
        head1 = head1->next;
        delete temp;
    }
    while (head2) {
        ListNode* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}

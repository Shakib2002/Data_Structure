#include <iostream>
using namespace std;

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int findIndex(ListNode* head, int target) {
    int index = 0;
    while (head) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;  
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int val;
        cin >> val;
        ListNode* head = new ListNode(val);
        ListNode* current = head;

 
        while (cin >> val && val != -1) {
            current->next = new ListNode(val);
            current = current->next;
        }

        int target;
        cin >> target;

 
        int result = findIndex(head, target);
        cout << result << endl;

 
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}


 
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

// Function to append a node at the end of the doubly linked list
void append(Node** head, int data) {
    Node* newNode = new Node(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* lastNode = *head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }
}

// Function to check if the doubly linked list is a palindrome
bool is_Palindrome(Node* head) {
    if (!head) return true;

    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    Node* prev = nullptr;
    Node* curr = slow;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    // Compare the first half and the reversed second half
    Node* first = head;
    Node* second = prev; // prev is now the head of the reversed second half
    while (second != nullptr) {
        if (first->data != second->data) {
            return false;
        }
        first = first->next;
        second = second->next;
    }

    return true;
}

int main() {
    int num;
    while (cin >> num) {
        Node* head = nullptr;
        while (num != -1) {
            append(&head, num);
            cin >> num;
        }

        if (!is_Palindrome(head)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

        // Clean up the linked list
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}

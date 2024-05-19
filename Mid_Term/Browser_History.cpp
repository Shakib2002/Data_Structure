#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
    Node(string val) : data(val), next(nullptr), prev(nullptr) {}
};

void insert_At_End(Node*& head, Node*& tail, string val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

Node* find_Node(Node* head, const string& val) {
    Node* curr = head;
    while (curr) {
        if (curr->data == val) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    string value;

    while (true) {
        cin >> value;
        if (value == "end") {
            break;
        }
        insert_At_End(head, tail, value);
    }

    int Q;
    cin >> Q;
    cin.ignore();

    Node* current = head;
    string command;

    while (Q--) {
        getline(cin, command);

        if (command.find("visit") == 0) {
            string address = command.substr(6);
            Node* targetNode = find_Node(head, address);
            if (targetNode) {
                current = targetNode;
                cout << current->data << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "next") {
            if (current && current->next) {
                current = current->next;
                cout << current->data << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "prev") {
            if (current && current->prev) {
                current = current->prev;
                cout << current->data << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
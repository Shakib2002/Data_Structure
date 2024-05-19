#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, Node*& tail, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

std::pair<int, int> findMinMax(Node* head) {
    if (head == nullptr) {
        return {std::numeric_limits<int>::min(), std::numeric_limits<int>::max()};
    }

    int maxVal = head->data;
    int minVal = head->data;

    Node* temp = head;
    while (temp!= nullptr) {
        maxVal = std::max(maxVal, temp->data);
        minVal = std::min(minVal, temp->data);
        temp = temp->next;
    }

    return {maxVal, minVal};
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int value;

    while (true) {
        std::cin >> value;
        if (value == -1) break;
        insertNode(head, tail, value);
    }

    std::pair<int, int> result = findMinMax(head);
    int difference = result.first - result.second;
    std::cout << difference << std::endl;

    while (head!= nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
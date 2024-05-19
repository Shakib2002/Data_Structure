#include<bits/stdc++.h>
using namespace std;

void print_List(const list<int>& lst) {
    cout << "L -> ";
    for (int val : lst) {
        cout << val << " ";
    }
    cout <<endl;

    cout << "R -> ";
    for (auto it = lst.rbegin(); it!= lst.rend(); ++it) {
         cout << *it << " ";
    }
    cout <<endl;
}

int main() {
    int Q;
    cin >> Q;

    list<int> dll;

    for (int i = 0; i < Q; ++i) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            dll.push_front(V);
        } else if (X == 1) {
            dll.push_back(V);
        } else if (X == 2) {
            if (V >= 0 && V < dll.size()) {
                auto it = dll.begin();
                advance(it, V);
                dll.erase(it);
            }
        }

        print_List(dll);
    }

    return 0;
}
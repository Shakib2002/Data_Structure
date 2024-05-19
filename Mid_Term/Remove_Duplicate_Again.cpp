#include<bits/stdc++.h>
using namespace std;

void print_List(const list<int>& lst) {
    for (int x : lst) {
        cout << x << " ";
    }
    cout <<endl;
}

int main() {
    list<int> lst;
    int num;

     
    while (cin >> num && num!= -1) {
        lst.push_back(num);
    }

    lst.sort();
    lst.unique();

     
    print_List(lst);

    return 0;
}
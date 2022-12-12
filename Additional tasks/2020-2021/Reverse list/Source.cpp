#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    int getLength() {
        Node* temp = head;

        int res = 0;
        while (temp) {
            temp = temp->next;
            res++;
        }
        return res;
    }

    void reverse(int from, int to) {
        
        if (from >= getLength())
        {
            return;
        }

        if (to > getLength())
        {
            to = getLength();
        }

        vector<int> vals(to - from + 1);

        Node* start = head;

        for (int i = 1; i < from; i++)
        {
            start = start->next;
        }

        Node* end = start;
        int j = 0;
        for (int i = from; i <= to; i++)
        {
            vals[j] = end->data;
            end = end->next;
            j++;
        }

        while (start != end) {
            j--;
            start->data = vals[j];
            start = start->next;
        }
    }

    void print() {
        Node* temp = head;

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~List() {
        Node* curr = head;

        while (curr) {
            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }

        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

        string op;
        cin >> op;

        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }

        if (op == "print") {
            testList.print();
        }

        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }

    return 0;
}
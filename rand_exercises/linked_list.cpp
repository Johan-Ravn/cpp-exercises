#include <vector>
#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int value;
    Node *next;
};

void insert_node(Node *&head, int value) {
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = head;
    head = new_node;
}

void print_list(Node *head) {
    while (head->next != nullptr) {
        cout << head->value << endl;
        head = head->next;
    }
    return;
}

void deallocate_list(Node *head) {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

vector<int> create_arr(int size) {
    vector<int> arr;
    for (int i = 0; i < size; i++) {
        arr.push_back(i);
    }
    return arr;
}

int main() {
    vector<int> arr = create_arr(10);
    Node *head = new Node;
    head->next = nullptr;

    for (int i : arr) {
        insert_node(head, arr[i]);
    }
    print_list(head);

    deallocate_list(head);
    return 0;
}


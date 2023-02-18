#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int i) {
        this->data = i;
        this->next = NULL;
    }
};

void nodePushBack(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return ;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return;
}

void insertAtMiddle(Node* head, int data, int pos) {
    Node* temp = head;
    for (int i = 1; i < pos-1; i++) {
        temp = temp->next;
    }

    Node* temp_node = temp->next;
    temp->next = new Node(data);
    temp->next->next = temp_node;

}

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> " ;
        temp = temp->next;
    }
    cout << endl;
}

int main(void) {
    Node* head = NULL;

    for (int i = 0; i < 10; i++) {
        nodePushBack(head, i);
    }

    printList(head);
    insertAtMiddle(head, 10, 4);
    printList(head);

    return 0;
}
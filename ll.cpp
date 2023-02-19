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

void insertAtHead(Node* &head, int data) {
    if (head == NULL) {
        head = new Node(data);
        return ;
    }

    Node* temp = head;
    head = new Node(data);
    head->next = temp;
}

Node* reverse(Node* &head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = current;

    while (next != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

Node* recReverse(Node* node) {
    if (node == NULL || node->next == NULL) return node;

    Node* sHead = recReverse(node->next);

    node->next->next = node;
    node->next = NULL;

    return sHead;
}

Node* midPoint(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> " ;
        temp = temp->next;
    }
    cout << endl;
}

Node* kReverse(Node* node, int k) {
    if (node == NULL) return NULL;

    Node* current = node;
    Node* next = node;
    Node* prev = NULL;

    int cnt = 1;
    while (current != NULL && cnt <= k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        cnt++;
    }

    if (next != NULL) node->next = kReverse(next, k);

    return prev;
}

Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* temp = NULL;
    if (a->data < b->data) {
        temp = a;
        temp->next = merge(a->next, b);
    } 
    else {
        temp = b;
        temp->next = merge(a, b->next);
    }

    return temp;
}

int main(void) {
    Node* head = NULL;

    for (int i = 0; i < 10; i++) {
        nodePushBack(head, i);
    }

    printList(head);
    insertAtMiddle(head, 10, 4);
    printList(head);
    insertAtHead(head, 13);
    printList(head);
    cout << "Midpoint: " << midPoint(head)->data << endl;
    reverse(head);
    printList(head);
    head = recReverse(head);
    printList(head);
    head = kReverse(head, 3);
    printList(head);

    cout << endl;

    Node* a = NULL;
    cout << "a: " << endl;
    insertAtHead(a, 10);
    insertAtHead(a, 7);
    insertAtHead(a, 5);
    insertAtHead(a, 1);
    insertAtHead(a, 17);
    insertAtHead(a, 2);
    insertAtHead(a, 14);
    printList(a);
    cout << endl;

    Node* b = NULL;
    cout << "b: " << endl;
    insertAtHead(b, 6);
    insertAtHead(b, 3);
    insertAtHead(b, 2);
    printList(b);
    cout << endl;

    cout << "Merged: " << endl;
    a = merge(a, b);
    printList(a);
    return 0;
}
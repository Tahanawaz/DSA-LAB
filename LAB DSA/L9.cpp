#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev; // Added for reverse traversal

    Node(int value) : data(value), next(NULL), prev(NULL) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(NULL) {}

    void insertAtFirst(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtLast(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void insertAtNth(int value, int n) {
        if (n < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (n == 1) {
            insertAtFirst(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < n - 1; i++) {
            if (temp == NULL || temp->next == head) {
                cout << "Position out of bounds!" << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertAtCenter(int value) {
        if (head == NULL) {
            insertAtFirst(value);
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newNode = new Node(value);
        newNode->next = slow->next;
        newNode->prev = slow;
        slow->next->prev = newNode;
        slow->next = newNode;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    void displayReverse() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head->prev; // Start from the tail
        do {
            cout << temp->data << " -> ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << "(back to tail)" << endl;
    }

    ~CircularLinkedList() {
        if (head == NULL) return;
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtFirst(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtNth(25, 2);
    list.insertAtCenter(15);

    cout << "Circular Linked List: ";
    list.display();

    cout << "Circular Linked List in Reverse: ";
    list.displayReverse();

    return 0;
}

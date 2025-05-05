#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class StackLinkedList {
    Node* top;

public:
    StackLinkedList() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << top->data << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    StackLinkedList sl;
    sl.push(100);
    sl.push(200);
    sl.push(300);
    sl.display();
    sl.pop();
    sl.display();
    return 0;
}


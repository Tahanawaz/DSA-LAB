#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

class QueueLinkedList {
    Node* front;
    Node* rear;
public:
    QueueLinkedList() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow"<<endl;
            return;
        }
        cout << "Dequeued: " << front->data << endl;
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
    }
    void display() {
        if (front == NULL) {
            cout << "Queue is Empty"<<endl;
            return;
        }
        cout << "Queue (front to rear): ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    QueueLinkedList ql;
    ql.enqueue(100);
    ql.enqueue(200);
    ql.enqueue(300);
    ql.display();
    ql.dequeue();
    ql.display();
    return 0;
}


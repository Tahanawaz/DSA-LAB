#include <iostream>
using namespace std;

const int SIZE = 100;

class QueueArray {
    int front, rear;
    int arr[SIZE];

public:
    QueueArray() {
        front = rear = -1;
    }

    void enqueue(int x) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
        if (front > rear) front = rear = -1;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    QueueArray qa;
    qa.enqueue(10);
    qa.enqueue(20);
    qa.enqueue(30);
    qa.display();
    qa.dequeue();
    qa.display();
    return 0;
}


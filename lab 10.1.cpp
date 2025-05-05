#include <iostream>
using namespace std;
const int SIZE = 100;
class StackArray {
    int top;
    int arr[SIZE];
public:
    StackArray() {
        top = -1;
    }
    void push(int x) {
        if (top >= SIZE - 1) {
            cout << "Stack Overflow"<<endl;
            return;
        }
        arr[++top] = x;
    }
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow"<<endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }
    void display() {
        if (top < 0) {
            cout << "Stack is Empty"<<endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main() {
    StackArray sa;
    sa.push(10);
    sa.push(20);
    sa.push(30);
    sa.display();
    sa.pop();
    sa.display();
    return 0;
}


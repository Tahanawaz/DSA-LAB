#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) 
    {
    	data=value;
    	next=NULL;
	};
};
class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() 
    {
    	head=NULL;
	}
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            std::cout << "Invalid position!" << std::endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            display();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            if (temp == NULL) {
                std::cout << "Position out of bounds!" << std::endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        display();
    }
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" <<endl;
    }

    ~SinglyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != NULL) {
            nextNode = current->next;
            delete current;
            current = nextNode; }  }
};
int main() {
    SinglyLinkedList list;
    list.insertAtPosition(10, 0);
    list.insertAtPosition(20, 1);
    list.insertAtPosition(15, 1);
    list.insertAtPosition(5, 0);
    list.insertAtPosition(25, 10);

    return 0;
}

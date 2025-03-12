#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
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

    void insertAtStart(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        display();
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
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
            current = nextNode;
        }
    }
};
int main() {
    SinglyLinkedList list;
    list.insertAtStart(10);
    list.insertAtEnd(20);
    list.insertAtStart(5);
    list.insertAtEnd(30);
}

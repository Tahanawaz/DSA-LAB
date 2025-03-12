#include <iostream>
using namespace std;
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
    SinglyLinkedList() {
	head=NULL;
	};
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
    }
    void displayFirstNode() {
        if (head != NULL) {
            cout << "First node= " << head->data << endl;
        } else {
            cout << "List is empty=" << endl;
        }
    }
    void displayLastNode() {
        if (head == NULL) {
            cout << "List is empty=" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        cout << "Last node= " << temp->data << endl;
    }
    void displayNthNode(int n) {
        if (n < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < n; i++) {
            if (temp == NULL) {
                cout << "Position out of bounds!" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp != NULL) {
            cout << "Nth node (" << n << "): " << temp->data << endl;
        } else {
            cout << "Position out of bounds!" << endl;
        }
    }
    void displayCenterNode() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Center node: " << slow->data << endl;
    }
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;   }
        cout << "NULL" << endl;
    }
    ~SinglyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != NULL) {
            nextNode = current->next;
            delete current;
			   current = nextNode;
        } }};
int main() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display();
    list.displayFirstNode();
    list.displayLastNode();
    list.displayNthNode(3);
    list.displayCenterNode();

    return 0;
}

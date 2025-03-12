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

    void deleteFirstNode() {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "First node deleted." << endl;
    }

    void deleteLastNode() {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Last node deleted." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Last node deleted." << endl;
    }

    void deleteNthNode(int n) {
        if (n < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (n == 1) {
            deleteFirstNode();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < n - 1; i++) {
            if (temp == NULL || temp->next == NULL) {
                cout << "Position out of bounds!" << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp->next == NULL) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        cout << "Nth node (" << n << ") deleted." << endl;
    }

    void deleteCenterNode() {
        if (head == NULL) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != NULL) {
            prev->next = slow->next;
            delete slow;
            cout << "Center node deleted." << endl;
        } else {
            delete head;
            head = NULL;
            cout << "Center node deleted." << endl;
        }
    }
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    ~SinglyLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != NULL) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }};
int main() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.display();
    list.deleteFirstNode();
    list.display();
    list.deleteLastNode();
    list.display();
    list.deleteNthNode(2);
    list.display();
    list.deleteCenterNode();
    list.display();
    
}

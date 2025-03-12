#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
         Node(int value) 
    {
    	data=value;
    	next=NULL;
    	prev=NULL;
	};

};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtFirst(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtLast(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
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
            if (temp == NULL) {
                cout << "Position out of bounds!" << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of bounds!" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtCenter(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        newNode->next = slow;
        newNode->prev = slow->prev;
        if (slow->prev != NULL) {
            slow->prev->next = newNode;
        } else {
            head = newNode; // Update head if inserting at the beginning
        }
        slow->prev = newNode;
    }

    void displayForward() {
        Node* temp = head;
        cout << "List (Forward): ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayReverse() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        cout << "List (Reverse): ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
    ~DoublyLinkedList() {
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
    DoublyLinkedList list;
    list.insertAtFirst(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtNth(25, 2);
    list.insertAtCenter(15);
    list.displayForward();
    list.displayReverse();

}

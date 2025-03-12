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
    SinglyLinkedList() {
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
    Node* getHead() {
        return head;
    }
    void display() {
        Node* temp = head;
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
    }
};
SinglyLinkedList mergeSinglyLinkedLists(SinglyLinkedList& list1, SinglyLinkedList& list2) {
    SinglyLinkedList mergedList;
    Node* head1 = list1.getHead();
    Node* head2 = list2.getHead();
    while (head1 != NULL) {
        mergedList.insertAtEnd(head1->data);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        mergedList.insertAtEnd(head2->data);
        head2 = head2->next;
    }
    return mergedList;
}
int main() {
    SinglyLinkedList list1;
    SinglyLinkedList list2;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list2.insertAtEnd(4);
    list2.insertAtEnd(5);
    list2.insertAtEnd(6);
    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();
    SinglyLinkedList mergedList = mergeSinglyLinkedLists(list1, list2);
    cout << "Merged List: ";
    mergedList.display();
    return 0;
}

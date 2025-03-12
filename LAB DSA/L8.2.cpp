#include <iostream>
using namespace std;
class DoublyNode {
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int value) 
       {
    	data=value;
    	next=NULL;
	}; 
};

class DoublyLinkedList {
private:
    DoublyNode* head;
public:
    DoublyLinkedList() : head(NULL) {}
    void insertAtEnd(int value) {
        DoublyNode* newNode = new DoublyNode(value);
        if (head == NULL) {
            head = newNode;
        } else {
            DoublyNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    DoublyNode* getHead() {
        return head;
    }
    void display() {
        DoublyNode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    ~DoublyLinkedList() {
        DoublyNode* current = head;
        DoublyNode* nextNode;
        while (current != NULL) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};
DoublyLinkedList mergeDoublyLinkedLists(DoublyLinkedList& list1, DoublyLinkedList& list2) {
    DoublyLinkedList mergedList;
    DoublyNode* head1 = list1.getHead();
    DoublyNode* head2 = list2.getHead();

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
    DoublyLinkedList list1;
    DoublyLinkedList list2;
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
    DoublyLinkedList mergedList = mergeDoublyLinkedLists(list1, list2);
    cout << "Merged List: ";
    mergedList.display();
    return 0;
}

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* insert(Node* root, int val) {
        if(root == NULL)
            return new Node(val);

        if(val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    void inorder(Node* root) {
        if(root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};
int main() {
    BST tree;
    Node* root = NULL;
    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 70);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 60);
    tree.insert(root, 80);

    cout << "BST Inorder Traversal: ";
    tree.inorder(root);
    cout << endl;

    return 0;
}


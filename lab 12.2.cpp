#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};
class AVL {
public:
    int getHeight(Node* n) {
        return n ? n->height : 0;
    }
    int getBalance(Node* n) {
        return n ? getHeight(n->left) - getHeight(n->right) : 0;
    }
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* insert(Node* root, int key) {
        if (root == NULL)
            return new Node(key);

        if (key < root->data)
            root->left = insert(root->left, key);
        else if (key > root->data)
            root->right = insert(root->right, key);
        else
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        // Left Left
        if (balance > 1 && key < root->left->data)
            return rightRotate(root);

        // Right Right
        if (balance < -1 && key > root->right->data)
            return leftRotate(root);

        // Left Right
        if (balance > 1 && key > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left
        if (balance < -1 && key < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main() {
    AVL tree;
    Node* root = NULL;
    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);

    cout << "AVL Inorder Traversal: ";
    tree.inorder(root);
    cout << endl;

    return 0;
}


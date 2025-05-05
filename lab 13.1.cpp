#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTreeDFS {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    void dfs(TreeNode* root) { 
	// Preorder
        if (root != NULL) {
            cout << root->data << " ";
            dfs(root->left);
            dfs(root->right);
        }
    }
};

int main() {
    BinaryTreeDFS tree;
    TreeNode* root = NULL;
    root = tree.insert(root, 40);
    tree.insert(root, 20);
    tree.insert(root, 60);
    tree.insert(root, 10);
    tree.insert(root, 30);

    cout << "DFS (Preorder) in Tree: ";
    tree.dfs(root);
    cout << endl;

    return 0;
}


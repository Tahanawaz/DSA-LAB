#include <iostream>
#include <queue>
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
class BinaryTreeBFS {
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
    void bfs(TreeNode* root) {
        if (root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }
    }
};

int main() {
    BinaryTreeBFS tree;
    TreeNode* root = NULL;
    root = tree.insert(root, 40);
    tree.insert(root, 20);
    tree.insert(root, 60);
    tree.insert(root, 10);
    tree.insert(root, 30);

    cout << "BFS (Level Order) in Tree: ";
    tree.bfs(root);
    cout << endl;

    return 0;
}


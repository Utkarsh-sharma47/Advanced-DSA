#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to perform vertical order traversal
void verticalOrder(Node* root, int hd, map<int, vector<int>> &m) {
    if (root == NULL) return;

    // Store the node's data in the map based on horizontal distance (hd)
    m[hd].push_back(root->data);

    // Recursive calls for left and right subtrees
    verticalOrder(root->left, hd - 1, m);
    verticalOrder(root->right, hd + 1, m);
}

int main() {
    // Constructing the tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(7);

    /*
           4
         /   \
        2     5
       / \   / \
      1   3 6   7
    */

    map<int, vector<int>> m;
    verticalOrder(root, 0, m);

    // Printing vertical order traversal
    for (auto it : m) {
        for (int val : it.second) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

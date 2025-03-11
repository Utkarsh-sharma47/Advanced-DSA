#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to calculate the height of the tree
int height(Node* root) {
    if (root == NULL) {
        return 0; // Base case: height of empty tree is 0
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to print only the leaf nodes
void printLeafNodes(Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main() {
    // Create the tree
    struct Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(6);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    root->left->right->left = new Node(69);

    
/*
                2
                / \
                4   6
               / \   
              1   3  
                 /
                69
*/
    // Calculate height
    int treeHeight = height(root);
    cout << "Height of the tree: " << treeHeight << endl;
    

    return 0;
}

#include<bits/stdc++.h>
using namespace std;


// 1. make Node format
struct Node{
    public:
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};

//3. PreOrder
void preorder(Node* root) {
    // Base case: if the node is NULL, return
    if (root == NULL) {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// 2. Make tree
int main()
{
    struct Node* root = new Node (1);
    root -> left = new Node (2);
    root -> right = new Node (3);
/*
    2
   / \
  4   6

*/

    root->left->left = new Node (4);
    root->left->right = new Node (5);

    root->right->left = new Node (6);
    root->right->right = new Node (7);
/*
       2
     /   \
    4     6
   / \   / \
  1   3 5   7

*/

   preorder(root);
   
    return 0;
}

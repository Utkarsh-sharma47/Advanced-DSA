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
/*
LCA
*/


Node* LCA(Node* root, int n1, int n2)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node* left = LCA(root->left, n1,n2);
    Node* right = LCA(root->right, n1,n2);

    if(left == NULL)
    {
        return right;
    }
    if(left == NULL)
    {
        return left;
    }

    return root;
}

int main()
{
    struct Node* root = new Node (1);

    root -> left = new Node (2);
    root -> right = new Node (3);

    root->left->left = new Node (4);
    root->right->left = new Node (5);
    root->right->right = new Node (6);

    root->right->left->right = new Node (7);
/*
       1
     /   \
    2     3
   /     / \
  4     5   6
       /     
      7       
*/
    struct Node* lca = LCA(root,7,4);
    cout<<lca->data;

    return 0;
}

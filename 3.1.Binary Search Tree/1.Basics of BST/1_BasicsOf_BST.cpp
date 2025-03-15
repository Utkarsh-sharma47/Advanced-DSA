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
//Insert in BST 
Node* insertBST(Node* root, int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }

    if(val < root->data)
    {
        root->left = insertBST(root->left , val);
    }
    else
    {
        root->right = insertBST(root->right , val);
    }
    return root;
}

//search in BST
Node* searchBST(Node* root, int k)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == k)
    {
        return root;
    }
    else if (root->data < k)
    {
        searchBST(root->right, k);
    }
    else{
        searchBST(root->left, k);
    }
}

//Delete in BST


int main()
{
    struct Node* root = new Node (4);
    root -> left = new Node (2);
    root -> right = new Node (5);

    root->left->left = new Node (1);
    root->left->right = new Node (3);

    root->right->left = new Node (4);
    root->right->right = new Node (7);
/*
       4
     /   \
    2     5
   / \   / \
  1   3 4   7
*/
    struct Node* x = searchBST(root, 5);
    cout<<x->data;



    return 0;
}

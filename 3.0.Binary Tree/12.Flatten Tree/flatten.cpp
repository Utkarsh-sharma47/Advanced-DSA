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

//flatten binary tree
Node* flat(Node* root)
{
    if(root->left != NULL)
    {
        flat(root->left);
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flat(root->right);

    
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

    return 0;
}

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



    return 0;
}

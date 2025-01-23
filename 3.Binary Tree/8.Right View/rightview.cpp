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
    struct Node* root = new Node (2);
    root -> left = new Node (4);
    root -> right = new Node (6);

    root->left->left = new Node (1);
    root->left->right = new Node (3);

    root->right->left = new Node (5);
    root->right->right = new Node (7);
/*
       2
     /   \
    4     6
   / \   / \
  1   3 5   7
*/



    return 0;
}

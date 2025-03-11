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
Shortest distance between two nodes in Binary Tree
it is the minimum number of edges to be traversed 
to reach from one node to another node.
*/

int mindist;
int findminDist(Node* root, int n1, int n2)
{
    if(!root)
    {
        return 0;
    }
    int left = findminDist(root->left, n1, n2);
    int right = findminDist(root->right, n1, n2);

    if(left && right)
    {
        mindist =  left+right;
        return 0;
    }
    else if(root->data==n1 || root->data == n2)
    {
        if(left || right)
        {
            mindist = max(left,right);
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(left || right)
    {
        return max(left, right)+1;
    }
    return 0;

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
    cout<<findminDist(root, 4,3 );

    return 0;
}

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

void leftview(Node* root)
{
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        for(int i=1; i<=n; i++)
        {
            Node* temp = q.front();

            if(i==1)
            {
                cout<<temp->data<<" ";
            }
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        

    }

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

    leftview(root);

    return 0;
}

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

int KthSum(Node* root, int k) {
    if(root==NULL)
    {
        return -1;
    }
    //make a queue and push root+NULL so that we know 0th level is finished
    int sum =0;
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    int i=1;
    //make a pointer to front node
    while(i<=k)
    {
        Node* frontnode = q.front();
        q.pop();
        if(frontnode!=NULL)
        {
            cout<<frontnode->data<<" ";
            sum = sum + frontnode->data;
            if(i==k)
            {
                q.push(frontnode->left);
            }
            if(frontnode->right!=NULL)
            {
                q.push(frontnode->right);
            }
        }
        // if node is null and queue is not empty
        else if(!q.empty())
        {
            q.push(NULL);
            i++;
        }

    }
    cout<<endl;
    return sum;
}

// 2. Make tree
int main()
{
    struct Node* root = new Node (2);
    root -> left = new Node (4);
    root -> right = new Node (6);
/*
    2
   / \
  4   6
*/

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

   cout<<KthSum(root,2);


    return 0;
}

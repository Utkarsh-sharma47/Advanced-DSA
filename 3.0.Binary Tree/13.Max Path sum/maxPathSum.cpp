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

int maxSumUtil(Node* root, int &ans)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = maxSumUtil(root->left, ans);
    int right = maxSumUtil(root->right, ans);

    int nodeMax = max(root->data,
                         max(root->data+left , root->data +right));
    ans = max(ans, nodeMax);
    int singlePath = max(root->data+left, root->data+right);
    return singlePath;
}

int maxsum(Node* root)
{
    int ans = INT_MIN;
    maxSumUtil(root, ans);
    return ans;
}


int main()
{
    struct Node* root = new Node (1);

    root -> left = new Node (2);
    root -> right = new Node (3);

    root->left->left = new Node (4);
    root->right->left = new Node (5);
    root->right->right = new Node (6);

    root->right->left->right = new Node (-7);
/*
       1
     /   \
    2     3
   /     / \
  4     5   6
       /     
      7       
*/
    cout<<maxsum(root);

    return 0;
}

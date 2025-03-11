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

void printlevel(Node* root)
{
    if(root==NULL)
    {
        return ;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop(); // pop this node
        if(node != NULL)
        {
            cout<<node->data<<" ";
            if(node->left != NULL)
            {
                q.push(node->left);
            }
            if(node->right != NULL)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty()) //agar null aaya and qeue empty nhi ho
        {
            q.push(NULL); //null phir daal do
        }
    }

}

// 2. Make tree
int main()
{
    struct Node* root = new Node (1);
    root -> left = new Node (2);
    root -> right = new Node (3);

    root->left->left = new Node (4);
    root->left->right = new Node (5);

    root->right->left = new Node (6);
    root->right->right = new Node (7);

    printlevel(root);


    return 0;
}

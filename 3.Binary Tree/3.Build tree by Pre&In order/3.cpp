#include<bits/stdc++.h>
using namespace std;

struct Node {
    public:
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search (int in[], int start,int end,int curr)
{
    for(int i=start; i<=end; i++)
    {
        if(in[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

Node* buildtree(int pre[], int in[], int start, int end)
{
    static int index = 0;
    int curr = pre [index];
    index++;
 
    Node* node = new Node(curr);
    if(end==start)
    {
        return node;
    }
    int pos = search(in,start,end,curr);

    node->left = buildtree(pre,in,0,pos-1);
    node->right = buildtree(pre,in,pos+1,end);
}


// 2. Make tree
int main()
{
    int pre[]={1,2,4,3,5}; 
    int in[]={4,2,1,5,3}; 
    
    buildtree(pre,in,0,4);
    
    struct Node* root  = new N

    return 0;
}

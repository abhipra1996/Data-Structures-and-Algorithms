/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false

int sum(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    return root->data+sum(root->left)+sum(root->right);
}


bool isSumTree(Node* root)
{
     if(root==NULL || root->left==NULL && root->right==NULL)
     {
         return true;
     }
     
     int l,r;
     l=sum(root->left);
     r=sum(root->right);
     //cout << l << " " << r << endl;
     return (root->data==l+r) && isSumTree(root->left) && isSumTree(root->right);
}

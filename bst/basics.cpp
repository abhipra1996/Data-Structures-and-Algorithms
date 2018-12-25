#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	struct node *left;
	struct node *right;
};


struct node *newnode(int data)
{
	struct node *tnode=NULL;
	tnode->val=data;
	tnode->left=NULL;
	tnode->right=NULL;
	return tnode;
}

struct node *insert(struct node *root,int data)
{
	if(root==NULL)
	{
		
		//cout<< "bc" <<endl;
		struct node *newnode=NULL;
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->val=data;
		newnode->right=NULL;
		newnode->left=NULL;
		return newnode;
		cout<<"nikl gya" <<endl;
		//return root;
	}
	
	if(data<root->val)
	{
		root->left=insert(root->left,data);
	}
	else if(data>root->val)
	{
		root->right=insert(root->right,data);
	}
	
	return root;

}

void inorder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

int main()
{
	int n;
	cin >> n;
	struct node *root=NULL;
	for(int i=0;i<n;i++)
	{
		int k;
		cin >> k;
		root=insert(root,k);
	}
	inorder(root);
	cout << endl;
	return 0;
}

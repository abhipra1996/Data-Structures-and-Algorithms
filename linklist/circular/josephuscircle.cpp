#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	struct node *next;
};

struct node *insert(struct node *head,int data)
{
	struct node *newnode=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->val=data;
	newnode->next=newnode;
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
		return head;
	}
	struct node*temp=NULL;
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=head;
	return head;
}

struct node *insertathead(struct node *head,int data)
{
	struct node *newnode=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->val=data;
	newnode->next=newnode;
	if(head==NULL)
	{
		head=newnode;
		return head;
	}
	struct node *temp=NULL;
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	newnode->next=head;
	temp->next=newnode;
	head=newnode;
	return head;
}

void print(struct node *head)
{
	if(head==NULL)
	{
		cout << "EMPTY LIST " << endl ;
		return ;
	}
	struct node *temp=NULL;
	temp=head;
	do{
			cout << temp->val << " ";
	        temp=temp->next;
	}	while(temp!=head);
	cout << endl ;
}

struct node *deletelast(struct node *head)
{
	if(head==NULL)
	{
		return head;
	}
	struct node *temp=NULL,*curr=NULL;
	curr=head;
	while(curr->next!=head)
	{
		temp=curr;
		curr=curr->next;
	}
	temp->next=head;
	free(curr);
	return head;
}

struct node *deletefirst(struct node *head)
{
	if(head==NULL)
	{
		return head;
	}
	struct node *temp=head,*curr=head;
	while(curr->next!=head)
	{
		curr=curr->next;
	}
	curr->next=head->next;
	head=head->next;
	free(temp);
	return head;
}

void josephuscircle(struct node *head,int m,int n)
{
	struct node *curr=NULL;
	curr=head;
	for(int i=n;i>1;i--)
	{
		for(int j=0;j<m-1;j++)
		{
			curr=curr->next;
		}
		cout << "NODE REMOVED IS : " << curr->next->val << endl ;
		curr->next=curr->next->next;
	}
	cout << "LAST NODE IS : " << curr->val;
}

int main()
{
	struct node *head=NULL;
	int n,i;
	cout << "ENTER THE NUMBER OF NODES : " << endl ;
	cin >> n;
	cout << "ENTER THE NODES : " << endl;
	for(i=1;i<=n;i++)
	{
		//int z;
		//cin >> z;
		head=insert(head,i);
		//head=insertathead(head,z);
	}
	print(head);
	int m;
	cin >> m ;
	josephuscircle(head,m,n);
	//head=deletelast(head);
	//head=deletefirst(head);
	//print(head);
	return 0;
}

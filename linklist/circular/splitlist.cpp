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

void splitlist(struct node *head,struct node **a,struct node **b)
{
	struct node *slow=NULL,*fast=NULL;
	slow=head;
	fast=head;
	while(fast->next!=head && fast->next->next!=head)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	if(fast->next->next==head)
	{
		fast=fast->next;
	}
    *b=slow->next;              //start of 2nd list
	*a=head;                    //start of 1st list
	fast->next=slow->next;      //making 2nd list circular
	slow->next=head;           //making 1st list circular
}
void sortedinsert(struct node **head,int data)
{
	struct node *newnode=NULL,*curr=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->val=data;
	newnode->next=newnode;
	curr=*head;
	if(curr==NULL)
	{
		*head=newnode;
		return ;
	}
	if(newnode->val <= curr->val)
	{
		while(curr->next!=*head)
		{
			curr=curr->next;
		}
		newnode->next=*head;
		curr->next=newnode;
		*head=newnode;
	}
	if(newnode->val > curr->val)
	{
		struct node *pre=NULL;
		while(curr->next!=*head && newnode->val > curr->val )
		{
			pre=curr;
			curr=curr->next;
		}
		pre->next=newnode;
		newnode->next=curr;
	}
}

int main()
{
	struct node *head=NULL,*a=NULL,*b=NULL;
	int n,i;
	cout << "ENTER THE NUMBER OF NODES : " << endl ;
	cin >> n;
	cout << "ENTER THE NODES : " << endl;
	for(i=0;i<n;i++)
	{
		int z;
		cin >> z;
		head=insert(head,z);
	}
	print(head);
	//splitlist(head,&a,&b);
	//print(a);
	//print(b);
	int t;
	cin >> t ;
	sortedinsert(&head,t);
	print(head);
	return 0;
}

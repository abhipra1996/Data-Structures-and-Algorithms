#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	struct node *next;
	struct node *pre;
};

struct node *insert(struct node *head,int data)
{
	struct node *newnode=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->val=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		newnode->pre=NULL;
		head=newnode;
		return head;
	}
	struct node *temp=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->pre=temp;
	return head;
}

struct node *insertathead(struct node *head,int data)
{
	struct node *newnode=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->val=data;
	newnode->pre=NULL;
	newnode->next=head;
	if(head!=NULL)
	{
		head->pre=newnode;
	}
	head=newnode;
	return head;
}
struct node *insertatpos(struct node *head,int data,int pos)
{
	struct node *newnode=NULL;
	newnode=(struct  node *)malloc(sizeof(struct node));
	newnode->val=data;
	int count=0;
	struct node *temp=NULL;
	temp=head;
	if(pos==1)
	{
		head=insertathead(head,data);
		return head;
	}
	while(temp!=NULL && count<pos-2)
	{
		count++;
		temp=temp->next;
	}
	newnode->next=temp->next;
	if(temp->next!=NULL)
	{
		temp->next->pre=newnode;
	}
	newnode->pre=temp;
	temp->next=newnode;
	return head;
}

void print(struct node *head)
{
	if(head==NULL)
	{
		cout << "EMPTY HEAD " << endl ;
		return ;
	}
	struct node *temp=NULL,*last=NULL;
	temp=head;
	while(temp!=NULL)
	{
		cout << temp->val << " " ;
		last=temp;
		temp=temp->next; 
	}
	cout << endl ;
	while(last!=NULL)
	{
		 
		cout << last->val << " " ;
		last=last->pre;
	}
	cout << endl << endl;
}

struct node *deletehead(struct node *head)
{
	struct node *temp=NULL;
	temp=head;
	head=head->next;
	if(head!=NULL)
	{
		head->pre=NULL;
	}
	free(temp);
	return head;
}

struct node *deletelast(struct node *head)
{
	struct node *temp=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->pre->next=NULL;
	free(temp);
	return head;
}

struct node *deletepos(struct node *head,int pos)
{
	struct node *temp=NULL;
	temp=head;
	if(pos==1)
	{
		temp=head;
		head=head->next;
		head->pre=NULL;
		free(temp);
		return head;
	}
	pos=pos-1;
	while(pos-- && temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->pre->next=temp->next;
	temp->next->pre=temp->pre;
	free(temp);
	return head;
}

int main()
{
	struct node *head=NULL;
	int n,i;
	cout << "ENTER THE NUMBER OF NODES : " << endl ;
	cin >> n;
	cout << "ENTER THE NODES : " << endl;
	for(i=0;i<n;i++)
	{
		int z;
		cin >> z;
		head=insert(head,z);
		//head=insertathead(head,z);
	}
	print(head);
	/*int k,pos;
	cin >> k >> pos;
	head=insertatpos(head,k,pos);
	print(head);*/
	/*
	head=deletehead(head);
	print(head);
	head=deletelast(head);
	print(head);*/
	int k;
	cin >> k;
	head=deletepos(head,k);
	print(head);
	return 0;
}


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

struct node *reverse(struct node *head)
{
	struct node *temp=NULL,*curr=NULL;
	curr=head;
	while(curr!=NULL)
	{
		temp=curr->pre;
		curr->pre=curr->next;
		curr->next=temp;
		curr=curr->pre;
 	}
	if(temp!=NULL)
	{
		head=temp->pre;                   // making last node head
	}
	return head;
}

int length(struct node *head)
{
	struct node *temp=NULL;
	temp=head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
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
    //head=reverse(head);
    int t;
    cin >> t ;
	head=swapk(head,t);
	print(head);
	return 0;
}


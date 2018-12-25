#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	struct node *next;
};

struct node *insert(struct node *head,int data)
{
	struct node *newnode=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->val=data;
	newnode->next=NULL;
	if(head==NULL)
	{
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
	return head;
}

void print(struct node *head)
{
	if(head==NULL)
	{
		cout << "EMPTY LIST";
		return ;
	}
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout << temp->val << "  " ;
		temp=temp->next;
	}
	cout << endl ;
}
struct node *insertathead(struct node *head,int data)
{
	struct node *newnode=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->val=data;
	newnode->next=head;
	head=newnode;
	return head;
}


struct node *merge(struct node *a,struct node *b)
{
	if(a==NULL)
	{
		return b;
	}
	if(b==NULL)
	{
		return a;
	}
	struct node *res=NULL;
	if(a->val <= b->val)
	{
		res=a;
		res->next=merge(a->next,b);
	}
	else
	{
		res=b;
		res->next=merge(a,b->next);
	}
	return res;
}


int main()
{
	struct node *head=NULL,*head1=NULL;
	int n,i,n1;
	cout << "ENTER THE NUMBER OF NODES : " << endl ;
	cin >> n;
	cout << "ENTER THE NODES IN INCREASING ORDER: " << endl;
	for(i=0;i<n;i++)
	{
		int z;
		cin >> z;
		head=insert(head,z);
	}
	print(head);
	cout << "ENTER THE NUMBER OF NODES : " << endl ;
	cin >> n1;
	cout << "ENTER THE NODES IN INCREASING ORDER: " << endl;
	for(i=0;i<n1;i++)
	{
		int z1;
		cin >> z1;
		head1=insert(head1,z1);
	}
	print(head1);
	struct node *result=NULL;
	result=merge(head,head1);
	cout << "MERGED LIST IS : " << endl;
	print(result);
	return 0;
}

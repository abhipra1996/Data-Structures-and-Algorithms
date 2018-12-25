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
struct node *insertatpos(struct node *head,int data,int pos)
{
    struct node *newnode=NULL,*temp=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->val=data;
	int count=pos;
	count=count-2;
	temp=head;
	while(count--)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;	
	return head;
}
struct node *deletehead(struct node *head)
{
	struct node *temp=NULL;
	temp=head;
	head=temp->next;
	free(temp);
	return head;
}
struct node *deletepos(struct node *head,int pos)
{
	struct node *temp=NULL,*pre=NULL;
	temp=head;
	int count;
	count=pos-1;
	while(count--)
	{
		pre=temp;
		temp=temp->next;
	}
	pre->next=temp->next;
	free(temp);
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

struct node *deletelist(struct node *head)
{
	struct node *temp=NULL,*del=NULL;
	temp=head;
	while(temp!=NULL)
	{
		del=temp->next;
		free(temp);
		temp=del;
	}
	head=NULL;
	return head;
}

void search(struct node *head,int key)
{
	struct node *temp=NULL;
	temp=head;
	int pos=1;
	while(temp!=NULL)
	{
		if(temp->val==key)
		{
			cout << "FOUND AT " << pos << endl ;
			return ;
		}
		pos++;
		temp=temp->next;
	}
	cout << "NOT FOUND " << endl ;
	return ;
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
	/*int j,data;
	cout << "INSERT DATA AT POSITION : " ;
	cin >> data >> j;
	head=insertatpos(head,data,j);
	print(head);*/
	/*head=deletehead(head);
	print(head);
	int j,data;
	//cout << "INSERT DATA AT POSITION : " ;
	cin >> j;
	head=deletepos(head,j);
	print(head);*/
	int len;
	len=length(head);
	cout << "LENGTH = " << len << endl ; 
    search(head,4);
	print(head);
	return 0;
}

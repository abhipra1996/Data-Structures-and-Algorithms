#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	struct node *next;
};
//struct node *res=NULL;
struct node *insert(struct node *head,int data)
{
	struct node *newnode=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
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
		cout << "EMPTY LIST " << endl;
		return ;
	}
	struct node *temp=NULL;
	temp=head;
	while(temp!=NULL)
	{
		cout << temp->val << " " ;
		temp=temp->next;
	}
	cout << endl;
}


struct node *maxsumpath(struct node *a,struct node *b)
{
    struct node *res=NULL;
	while(a!=NULL || b!=NULL)
	{
	   if(a->val < b->val)
	   {
		res=insert(res,a->val);
		a=a->next;
	   }
	   else if(a->val > b->val)
	   {
		res=insert(res,b->val);
		b=b->next;
	   }
	   else
	   {
	   	res=insert(res,b->val);
		a=a->next;
	   	b=b->next;
	   }
	}
	
	return res;
}

int main()
{
	struct node *head=NULL,*head1=NULL,*result=NULL;
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
	int n1;
	cout << "ENTER THE NUMBER OF NODES : " << endl ;
	cin >> n1;
	cout << "ENTER THE NODES : " << endl;
	for(i=0;i<n1;i++)
	{
		int z1;
		cin >> z1;
		head1=insert(head1,z1);
	}
	print(head1);
	result=maxsumpath(head,head1);
	print(result);
	return 0;
}

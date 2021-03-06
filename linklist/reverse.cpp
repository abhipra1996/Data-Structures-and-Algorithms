#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	struct node *next;
};

struct node *a=NULL,*b=NULL;

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
struct node *middle(struct node *head)
{
	struct node *fast=NULL,*slow=NULL;
	fast=head;
	slow=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	cout << "MIDDLE ELEMENT IS : "<< slow->val << endl;
	return head;
}

struct node *swap(struct node *head,int x,int y)
{
	if(x==y)
	{
		return head;
	}
	struct node *currx=NULL,*prex=NULL,*curry=NULL,*prey=NULL;
	currx=head;
	curry=head;
	while(currx!=NULL  && currx->val!=x)
	{
		prex=currx;
		currx=currx->next;
	}
	while(curry!=NULL  && curry->val!=y)
	{
		prey=curry;
		curry=curry->next;
	}
	if(currx == NULL || curry == NULL)
	{
		cout << "VALUE NOT PRESENT"<< endl ;
		return head;
	}
	if(prex!=NULL)
	{
		prex->next=curry;
	}
	else
	{
		head=curry;
	}
	if(prey!=NULL)
	{
		prey->next=currx;
	}
	else
	{
		head=currx;
	}
	struct node *temp=NULL;
	temp=currx->next;
	currx->next=curry->next;
	curry->next=temp;
	return head;
}

struct node *reverse(struct node *head)
{
	struct node *pre=NULL,*curr=NULL,*next=NULL;
	curr=head;
	while(curr != NULL)
	{
		next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
	}
    head=pre;
    return head;
}

struct node *reversek(struct  node *head,int k)
{
	struct node *pre=NULL,*curr=NULL,*next=NULL;
	curr=head;
	int count=0;
	while(curr!=NULL && count<k)
	{
		next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
		count++;
	}
	if(next!=NULL)
	{
		head->next=reversek(next,k);
	}
	return pre;
}

struct node *altreversek(struct node *head,int k)
{
	struct node *pre=NULL,*curr=NULL,*next=NULL;
	curr=head;
	int count=0;
	while(curr!=NULL && count< k)
	{
		next=curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
		count++;
	}
	if(head!=NULL)
	{
		head->next=curr;
	}
	count=0;
	while(count<k-1 && curr!=NULL)
	{
		curr=curr->next;
		count++;
	}
	if(curr!=NULL)
	{
		curr->next=altreversek(curr->next,k);
	}
	return pre;
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
	}
	print(head);
    int k;
    cin >> k ;
    head=altreversek(head,k);
	print(head);
	return 0;
}

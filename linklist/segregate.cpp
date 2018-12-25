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
		cout << "EMPTY LIST" << endl;
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

struct node *segregatejoin(struct node *head)
{
	struct node *even=NULL,*odd=NULL,*temp=NULL;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->val%2==1)
		{
			odd=insert(odd,temp->val);
		}
		else
		{
			even=insert(even,temp->val);
		}
		temp=temp->next;
	}
	temp=even;
	while(even->next!=NULL)
	{
		even=even->next;
	}
	even->next=odd;
	return temp;
}
struct node *newnode(int data)
{
	struct node *n=NULL;
	n=(struct node *)malloc(sizeof(struct node));
	n->val=data;
	n->next=NULL;
	return n;
}
struct node *segregate(struct node *head)
{
	struct node *end=NULL,*temp=NULL,*pre=NULL,*end1=NULL;
	end=head;
	while(end->next!=NULL)
	{
		end=end->next;
	}
	end1=end;
	temp=head;
	while(temp!=end)
	{
		if(temp->val%2==1)
		{
			struct node *tmp=NULL;
			tmp=temp->next;
			end1->next=temp;
			end1->next->next=NULL;
			pre->next=tmp;
			free(tmp);
		}
		else
		{
			pre=temp;
			temp=temp->next;
		}
	}
	return head;
}
struct node *add(struct node *a,struct node *b)
{
	struct node *res=NULL;
	int carry=0,sum=0;
	while(a!=NULL || b!=NULL)
	{
		sum = carry;
		if(a!=NULL)
		{
			sum+=a->val;
			a=a->next;
		}
		else
		{
			sum+=0;
		}
		if(b!=NULL)
		{
			sum+=b->val;
			b=b->next;
		}
		else
		{
			sum+=0;
		}
		if(sum>9)
		{
			carry=1;
			sum=sum%10;
		}
		else
		{
			carry=0;
		}
        res=insertathead(res,sum);
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
		head=insertathead(head,z);
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
		head1=insertathead(head1,z1);
	}
	print(head1);
	result=add(head,head1);
    head=segregatejoin(head);
	print(result);
	return 0;
}

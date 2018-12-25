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


struct node *sortedinsert(struct node *head,int data)
{
       struct node *newnode=NULL,*temp=NULL,*pre=NULL;
       newnode=(struct node *)malloc(sizeof(struct node));
	   newnode->val=data;
       newnode->next=NULL;
       if(head==NULL)
	   {
	   	 head=newnode;
	   	 return head;
       }
       if(data <= head->val )
       {
       	 temp=head;
       	 newnode->next=head;
       	 head=newnode;
       	 return head;
       }
       else
       {
       	temp=head;
        while(temp->val < newnode->val && temp!=NULL)
        {
       	 pre=temp;
       	 temp=temp->next;
        }
        newnode->next=pre->next;
        pre->next=newnode;
        return head;
       }
       
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

		int k;
	    cin >> k;
	    head=sortedinsert(head,k);
	    print(head);
		

	return 0;
}

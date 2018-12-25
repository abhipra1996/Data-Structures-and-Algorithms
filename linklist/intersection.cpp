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



/*
struct node *intersect(struct node *head,struct node *head1)
{
	struct node *curr=NULL,*pre=NULL;
	curr=head;
	unordered_set<int> seen; //creating hash
    while(curr!=NULL)
    {
    	seen.insert(curr->val);
    	curr=curr->next;
    }
    curr=head1;
    struct node *result=NULL;
    while(curr!=NULL)
    {
    	if(seen.find(curr->val)!=seen.end())
    	{
    		result=insert(result,curr->val);
    	}
    	curr=curr->next;
    }
	return result;
} //doesnot work in devc++ but works on ideone
// O(n) solution
*/

struct node *intersectrec(struct node *a,struct node *b)
{
	if(a==NULL || b==NULL)
	{
		return NULL;
	}
	
	if(a->val < b->val)
	{
	    return intersectrec(a->next,b);
	}
	if(a->val > b->val)
	{
		return intersectrec(a,b->next);
	}
	
	struct node *temp=NULL;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val=a->val;
	temp->next=intersectrec(a->next,b->next);
	return temp;
}

int main()
{
    struct node *head=NULL,*head1=NULL,*res=NULL;
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
	res=intersectrec(head,head1);
	print(res);
	return 0;
}

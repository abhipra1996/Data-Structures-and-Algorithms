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

bool ispalin_stack(struct node *head)
{
	struct node *temp=NULL;
	temp=head;
	stack<int> store;
	bool res=true;
	if(head!=NULL && head->next!=NULL)
	{
	  while(temp!=NULL)
	  {  
		int k;
		k=temp->val;
		store.push(k);
		temp=temp->next;
	  } 
	  temp=head;
	  while(temp!=NULL)
	  {
		int j;
		j=store.top();
		if(temp->val == j)
		{
			temp=temp->next;
			store.pop();
		}
		else
		{
			return false;
		}
	  }
	  res=true;	
	}
	return res;
}


bool comparelist(struct node *a,struct node *b)
{
	struct node *temp1=NULL,*temp2=NULL;
	temp1=a;
	temp2=b;
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->val != temp2->val)
		{
			return false;
		}
		else
		{
			temp1=temp1->next;
			temp2=temp2->next;
		}
	}
	if (temp1==NULL && temp2==NULL)
	{
		return true;
	}
	return false;
}
bool ispalin(struct node *head)
{
	struct node *slow=NULL,*fast=NULL,*slow_pre=NULL,*midnode=NULL;
	slow=head;
	fast=head;
	bool res=true;
	if(head!=NULL && head->next!=NULL)
	{
	  while(fast!=NULL && fast->next!=NULL)
	  {
		fast=fast->next->next;
		
		slow_pre=slow;
		slow=slow->next;
	  } 
	  if(fast!=NULL)
	  {
		midnode=slow;
		slow=slow->next;
	  }
	  struct node *secondhalf=NULL;
	  secondhalf=slow;
	  slow_pre->next=NULL;
	  secondhalf=reverse(secondhalf);
	
	  res=comparelist(head,secondhalf);
	  secondhalf=reverse(secondhalf);
	  if(midnode!=NULL)
	  {
		slow_pre->next=midnode;
		midnode->next=secondhalf;
	  }
	  else
	  {
		slow_pre->next=secondhalf;
	  }	
	}
	
	return res;
}
struct node *altdelete(struct node *head)
{
	if(head==NULL)
	{
		return head;
	}
	struct node *temp=NULL;
	temp=head;
	while(temp!=NULL && temp->next!=NULL)
	{
		struct node *extra=NULL;
		extra=temp->next;
		free(temp->next);
		temp->next=extra->next;
		temp=temp->next;
	}
	return head;
}
void altprintrec(struct node *head)
{
	//struct node *temp=NULL;
	if(head==NULL & head->next==NULL)
	{
		return ; 
	}
	cout << head->val << " " ;
	altprintrec(head->next->next);
	//cout << head->val << " " ;
}
void altdeleterec(struct node *head)
{
	struct node *extra=NULL;
	extra=head->next;
	if(extra==NULL)
	{
		return ;
	}
	head->next=extra->next;
	free(extra);
	altdeleterec(head->next);
}

void altsplit(struct node *head)
{
	struct node *temp=NULL;
	temp=head;
	int counter=0;
	while(temp!=NULL)
	{
		if(counter%2==1)
		{
			a=insert(a,temp->val);
		}
		else
		{
			b=insert(b,temp->val);
		}
		counter++;
		temp=temp->next;
	}
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
	//head=altdelete(head);
	//altdeleterec(head);
	//altprintrec(head);
	altsplit(head);
	print(a);
	print(b);
	//print(head);
	return 0;
}

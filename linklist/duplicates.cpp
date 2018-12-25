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

struct node *sortedremovedup(struct node *head)
{
	struct node *curr=NULL,*pre=NULL,*temp=NULL;
	curr=head;
	while(curr->next!=NULL)
	{
		if(curr->val==curr->next->val)
		{
			temp=curr->next->next;
			free(curr->next);
			curr->next=temp;
		}
		else
		{
			curr=curr->next;
		}
	}
	return head;
}
/*
struct node *removeduph(struct node *head)
{
	struct node *curr=NULL,*pre=NULL;
	curr=head;
	unordered_set<int> seen; //creating hash
	while(curr!=NULL)
	{
		if(seen.find(curr->val)!=seen.end())
		{
			pre->next=curr->next;
			delete(curr);
		}
		else
		{
			seen.insert(curr->val);
			pre=curr;
		}
		curr=pre->next;
	}
	return head;
} //doesnot work in devc++ but works on ideone
// O(n) solution
*/
struct node *removedup(struct node *head)
{
	struct node *p1=NULL,*p2=NULL,*temp=NULL;
	p1=head;
	while(p1!=NULL && p1->next!=NULL )
	{
		p2=p1;
		while(p2->next!=NULL)
		{
			if(p1->val==p2->next->val)
			{
				temp=p2->next;
				p2->next=p2->next->next;
				delete(temp);
			}
			else
			{
					p2=p2->next;
			}		
		}
		p1=p1->next;
	}
	return head;
}//O(n^2) solution

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void pairwiseswap(struct node *head)
{
	struct node *temp=NULL;
	temp=head;
	if(temp!=NULL && temp->next!=NULL)
	{
		swap(&temp->val,&temp->next->val);
		pairwiseswap(temp->next->next);
	}
}
struct node *swaplinks(struct node *curr,struct node *pre)
{
	struct node *temp=NULL,*temp1;
	temp=pre->next;                   //1st node address
	temp1=curr->next->next;           
	
	
	pre->next=curr->next;
	curr->next->next=temp;
	curr->next=temp1;
	free(temp);
	free(temp1);
}
struct node *pairwiseswaplinks(struct node *head)
{
	struct node *temp=NULL,*pre=NULL;
	temp=head;
	while(temp!=NULL && temp->next!=NULL)
	{
		swaplinks(temp,pre);
		pre=temp->next;
		temp=temp->next->next;
	}
	return head;
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

		//int k;
	    //cin >> k;
	    //head=sortedremovedup(head);
	    //head=removedup(head);
	head=pairwiseswaplinks(head);
	print(head);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct trienode{
	map<int,struct trienode*> m;
	bool isend;
};

struct trienode* newnode()
{
	struct trienode *newnode=NULL;
	newnode=(struct trienode*)malloc(sizeof(struct trienode));
   	map<int,struct trienode*> temp;
	for(int j=0;j<26;j++)
	{
		temp[j]=NULL;
	}
	newnode->m=temp;
	newnode->isend=false;
	return newnode;
}

void insert(struct trienode *root,string str)
{
	int i,len;
	len=str.size();
	cout << len << endl;
	struct trienode *temp=NULL;
	temp=root;
	for(i=0;i<len;i++)
	{
		int index;
		index=str[i]-'a';
		//cout << index << endl;
		if(temp->m[index]==NULL)
		{
			trienode* x = new trienode();  // new thing :)
			temp->m[index]=x;
			//cout << "inserted : " << i << endl;
		}
		temp=temp->m[index];
	}
	temp->isend=true;
	//return root;
}

bool search(struct trienode *root,string str)
{
	int i,len;
	len=str.size();
	struct trienode *temp=NULL;
	temp=root;
	for(i=0;i<len;i++)
	{
		if(temp->m[str[i]-'a']==NULL)
		{
			return false;
		}
		temp=temp->m[str[i]-'a'];
	}
	return (temp!=NULL && temp->isend);
}

int main()
{
		cout << "ENTER NUMBER OF WORDS : " << endl;
		int n;
		cin >> n;
		//vector<string> v;
		struct trienode *root=NULL;
		root=newnode();
		cout << "ENTER THE WORDS : "<< endl;
		for(int i=0;i<n;i++)
		{
			string temp;
			cin >> temp;
			//cout << "start" << endl;
			insert(root,temp);
		}
		cout << "insertion done";
		int j;
		cin >> j;
		for(int i=0;i<j;i++)
		{
			string temp;
			cin >>  temp;
			if(search(root,temp))
			{
				cout << "FOUND !!!" << endl;
			}
			else
			{
				cout << "NOTFOUND!!!" << endl;
			}
		}
	return 0;
}

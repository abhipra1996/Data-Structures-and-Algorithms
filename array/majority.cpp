#include<bits/stdc++.h>
using namespace std;

int getcandidate(int a[],int n)              // MOOR VOTING ALGORITHM 	
{
	int maj=0,count=1;
	for(int i=0;i<n;i++)
	{
		if(a[maj]==a[i])
		{
			count++;
		}
		else
		{
			count--;
		}
		if(count==0)
		{
			maj=i;
			count=1;
		}
	}
	return a[maj];
}


void majority(int a[],int n)
{
	int candidate,i,count;
	candidate=getcandidate(a,n);
	for(i=0;i<n;i++)
	{
		if(a[i]==candidate)
		{
			count++;
		}
	}
	if(count>n/2)
	{
		cout << "majority element is : " << candidate;
		return ;
	}
	else
	{
		cout << "NO MAJORITY ELEMENT!!!  :p" ;
		return ;
	}

}

void majorityhash(int a[],int n)
{
	int i,index;
	int map[10000]={0};
	for(i=0;i<n;i++)
	{
		index=a[i];
		if(map[index]>n/2)
		{
			cout << "majority element is : " << a[i] ;
			return ;
		}
		else
		{
			map[index]+=1;
		}
	}
	cout << "NO MAJORITY ELEMENT " << endl;
	return ;
}

int main()
{
	int n,i;
	cout << "ENTER SIZE OF ARRAY : ";
	cin >> n;
	cout << "ENTER ELEMENTS OF ARRAY : " <<endl;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	//majority(a,n);
	majorityhash(a,n);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int > &a,int low,int high,int key)
{
	int mid;
	if(high>=low)
	{
		mid=(low+high)/2;
		if(key>a[mid-1] || mid==0 && (a[mid]==key))
		{
			return mid;
		}
		else if(a[mid]>key)
		{
			return binarysearch(a,0,mid-1,key);
		}
		else
		{
			return binarysearch(a,mid+1,high,key);
		}
	}
	return -1;
}

bool ismajority(vector<int > &a,int key)            // divide and conquer O(logn)
{
	int index,n;
	n=a.size()-1;
	index=binarysearch(a,0,n-1,key);
	if(index==-1)
	{
		return false;
	}
	if((index+(n/2)<=(n-1)) && a[index+(n/2)]==key)
	{
		return true;
	}
	return false;
}

bool linearismajority(vector<int > &a,int key)
{
	int i,max;
	max= a.size()%2?(a.size()/2)+1 : a.size()/2 ;
	for(i=0;i<max;i++)
	{
		if(a[i]==key && a[i+max]==key)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int n,i;
	cout << "ENTER SIZE OF ARRAY : ";
	cin >> n;
	cout << "ENTER ELEMENTS OF ARRAY : " <<endl;
	vector<int > a;
	for(i=0;i<n;i++)
	{
		int k;
		cin >> k;
		a.push_back(k);
	}
	int key;
	cin >> key;
    if(linearismajority(a,key))
    {
    	cout << "IS MAJORITY !!!" << endl ;
    }
    else
    {
    	cout << "NOT MAJORITY !!!" << endl ;
    }
	return 0;
}

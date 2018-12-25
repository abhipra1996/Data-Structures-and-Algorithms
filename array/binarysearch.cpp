#include<bits/stdc++.h>
using namespace std;

void binarysearch(int a[],int low,int high,int key)
{
	int mid=0;
	mid=(low+high)/2;
	if(high<low)
	{
		cout << "key not present" <<endl ;
		return ;
	}
	if(a[mid]==key)
	{
		cout << "KEY : " << key << "FOUND AT POSITION : " << mid  << endl ;
		return ; 
	}
	if(key>a[mid])
	{
		binarysearch(a,mid+1,high,key);
	}
	else
	{
		binarysearch(a,low,mid-1,key);
	}
}


int main()
{
	int n,i,key;
	cout << "ENTER THE SIZE OF ARRAY : " ;
	cin >> n ;
	int a[n];
	cout << "ENTER THE ELEMENTS OF ARRAY : " << endl;
	for(i=0;i<n;i++)
	{
		cin >> a[i] ;
	}
	cout << "ENTER KEY TO BE SEARCHED : " ;
	cin >> key ;
	binarysearch(a,0,n-1,key);
	return 0;
}

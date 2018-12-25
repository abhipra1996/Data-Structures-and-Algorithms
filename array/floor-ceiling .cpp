#include<bits/stdc++.h>
using namespace std;

int ceiling(vector<int> &a,int l,int h,int x)
{
	if(x<=a[l])
	{
		return l;
	}
	if(x>a[h])
	{
		return -1;
	}
	int mid;
	mid=(l+h)/2;
	if(a[mid]==x)
	{
		return mid;
	}
	else if(x>a[mid])
	{
		if(mid+1<=h && x<=a[mid+1])
		{
			return mid+1;
		}
		else
		return ceiling(a,mid+1,h,x);
	}
	else
	{
		if(l<=mid-1 && x>a[mid-1])
		{
			return mid-1;
		}
		else
		{
			return ceiling(a,l,mid-1,x);
		}
	}
}

int floor(vector<int> &a,int l,int h,int x)
{
	if(l>h)
	{
		return -1;
	}
	if(x>=a[h])
	{
		return h;
	}
	int mid;
	mid=(l+h)/2;
	if(a[mid]==x)
	{
		return mid;
	}
	if(mid>0 && x>=a[mid-1] && x<a[mid])
	{
		return mid-1;
	}
	if(x<mid)
	{
		return floor(a,l,mid-1,x);
	}
	return floor(a,mid+1,h,x);
}

void fc(vector<int > &a,int x)                       //unsorted array
{
	int ci,fi,fd,cd;
	fd=INT_MAX;
	cd=INT_MAX;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>x && cd >(a[i]-x) )
		{
			ci=i;
			cd=a[i]-x;
		}
		if(a[i]<x && fd > (x-a[i]))
		{
			fi=i;
			fd=x-a[i];
		}
	}
	if(cd==INT_MAX)
		{
			cout << "NO CEILING EXITS"  << endl;
		}
		else
		{
			cout << "CEILING IS " << a[ci] << endl;
		}
		if(fd==INT_MAX)
		{
			cout << "NO FLOOR EXITS"  << endl;
		}
		else
		{
			cout << "FLOOR IS " << a[fi] << endl;
		}
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
	int key,cindex,findex;
	cin >> key;
	/*
	cindex=ceiling(a,0,a.size()-1,key);
	findex=floor(a,0,a.size()-1,key);
	cout << "CEILING OF " << key << "is " << a[cindex] << endl;
	cout << "FLOOR OF " << key << "is " << a[findex] << endl;
	*/
	fc(a,key);
	return 0;
}

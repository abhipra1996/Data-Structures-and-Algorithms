#include<bits/stdc++.h>
using namespace std;


void merge(vector<int> &a,int l,int m,int h)
{
	int i,j,k,n1,n2;
	n1=m-l+1;
	n2=h-m;
	vector<int> v1(n1),v2(n2);
	for(i=0;i<n1;i++)
	{
		v1[i]=a[l+i];
	}
	for(j=0;j<n2;j++)
	{
		v2[j]=a[m+1+j];
	}
	i=0;
	k=l;
	j=0;
	
	while(i<n1 && j<n2)
	{
		if(v1[i]<=v2[j])
		{
			a[k]=v1[i];
			i++;
		}
		else
		{
			a[k]=v2[j];
			j++;
		}
		k++;
	}
	
	while(i<n1)
	{
		a[k]=v1[i];
		k++;
		i++;
	}
	
	while(j<n2)
	{
		a[k]=v2[j];
		j++;
		k++;
	}
	
}



void mergesort(vector<int> &a,int l,int h)
{
	int mid=0;
	if(l<h)
	{
		mid=(l+h)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,mid,h);
	}
	return ;
}


int main()
{
	int i,n;
	cin >> n ;
	vector<int> v;
	for(i=0;i<n;i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	mergesort(v,0,v.size()-1);
	for(i=0;i<n;i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}

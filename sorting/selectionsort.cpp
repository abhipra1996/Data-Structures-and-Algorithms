#include<bits/stdc++.h>
using namespace std;


void selectionsort(vector<int> &a)
{
	int i,j,temp,n;
	n=a.size();
	for(i=0;i<n-1;i++)
	{
		int minidx=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[minidx])
			{
				minidx=j;
			}
		}
		temp=a[i];
		a[i]=a[minidx];
		a[minidx]=temp;
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
	selectionsort(v);
	for(i=0;i<n;i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}

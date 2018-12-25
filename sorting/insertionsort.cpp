#include<bits/stdc++.h>
using namespace std;


void insertionsort(vector<int> &a)
{
	int i,j,temp,n,key,idx;
	n=a.size();
	for(i=1;i<n;i++)
	{
		j=i-1;
		key=a[i];
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
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
	insertionsort(v);
	for(i=0;i<n;i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}

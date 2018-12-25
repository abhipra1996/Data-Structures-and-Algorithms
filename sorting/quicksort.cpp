#include<bits/stdc++.h>
using namespace std;


int partition(vector<int> &a,int l,int h)
{
	int pivot,pindex,i;
	pindex=l;
	pivot=a[h];
	for(i=l;i<h;i++)
	{
		if(a[i]<=pivot)
		{
			int temp;
			temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	int temp;
	temp=a[pindex];
	a[pindex]=a[h];
	a[h]=temp;
	return pindex;
}



void quicksort(vector<int> &a,int l,int h)
{
	int pivot=0;
	if(l<h)
	{
		
		pivot=partition(a,l,h);
		quicksort(a,l,pivot-1);
		quicksort(a,pivot+1,h);
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
	quicksort(v,0,v.size()-1);
	for(i=0;i<n;i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}

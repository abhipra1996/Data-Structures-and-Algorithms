#include<bits/stdc++.h>
using namespace std;


void bubblesort(vector<int> &a)
{
	int i,j,temp,n;
	n=a.size();
	for(i=0;i<n;i++)
	{
		bool flag=true;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=false;
			}
		}
		if(flag)
		{
			break;
		}
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
	bubblesort(v);
	for(i=0;i<n;i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}

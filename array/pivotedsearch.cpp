#include<bits/stdc++.h>
using namespace std;

void pivotedsearch(vector<int> &a,int low,int high,int key)
{
	if(low>high)
	{
		cout << "KEY NOT PRESENT!!!" << endl;
		return ;
	}
	int mid;
	mid=(low+high)/2;
	if(a[mid]==key)
	{
		cout << "KEY FOUND AT"<< mid  << endl;
		return;
	}
	if(a[low]<=a[mid])
	{
		if(a[low]<=key && key<=a[mid])
		{
			pivotedsearch(a,low,mid-1,key);
		}
		pivotedsearch(a,mid+1,high,key);
	}
	if(key>=a[mid] && key <=a[high])
	{
		pivotedsearch(a,mid+1,high,key);
	}
	pivotedsearch(a,low,mid,key);
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
	int pos;
	cin >> pos;
	pivotedsearch(a,0,a.size()-1,pos);
	return 0;
}

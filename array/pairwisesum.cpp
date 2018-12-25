#include<bits/stdc++.h>
using namespace std;


void pairwisesum(vector<int> &a,int sum)
{
	sort(a.begin(),a.end());
	int l,r;
	l=0;
	r=a.size()-1;
	while(l<r)
	{
		if(a[l]+a[r]==sum)
	 { 
		cout << "PAIR FOUND :" << a[l] << " AND " << a[r];
		return ;
	 }
	    else  if(a[l]+a[r]<sum)
	 {
		l++;
	 }
	 else
	 {
		r--;
	 }	
	}
	cout << "pair not found " << endl ;
	return ;
}

void pairwisesumhash(vector<int> &a,int sum)
{
	bool map[100000]={0};
	int i,size,temp;
	size=a.size()-1;
	for(i=0;i<size;i++)
	{
		temp=sum-a[i];
		if(temp>=0 && map[temp]==1)
		{
			cout << "PAIR IS : " << temp << " AND " << a[i] << endl;
			return ;
		}
		else
		{
			map[a[i]]=1;
		}
	}
	cout << "PAIR NOT FOUND !!! " << endl ;
	return ;
}


int main()
{
	int n,i,key;
	cout << "ENTER THE SIZE OF ARRAY : " ;
	cin >> n ;
	vector<int> a;
	cout << "ENTER THE ELEMENTS OF ARRAY : " << endl;
	for(i=0;i<n;i++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}
	cout << "ENTER THE SUM : ";
	int sum;
	cin >> sum;
	//pairwisesum(a,sum);
	pairwisesumhash(a,sum);
	return 0;
}

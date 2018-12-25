#include<bits/stdc++.h>
using namespace std;

void pairwisesum(vector<int > &a,vector<int > &b,int sum)
{
	unordered_set<int > map;
	int temp=0,i,found=0;
	for(i=0;i<a.size();i++)
	{
		map.insert(a[i]);
	}
	for(i=0;i<b.size();i++)
	{
		temp=sum-b[i];
		if(map.find(temp)!=map.end())
		{
			cout << "Pair is " << temp << " And " << b[i] << endl ;
			found=1;
		}
	}
	if(found==0)
	{
		cout << "Pair not found " << endl ;
	}
	
}

void print(vector<int> &a)
{
	for(int i=0;i<a.size();i++)
	{
		cout << a[i] << " " ;
	}
	cout << endl ;
}

int main()
{
	int n,n1,i,sum;
	cout << "ENTER SIZE OF 1st ARRAY : " ;
	cin >> n;
	vector<int> v1,v2;
	cout << "ENTER ELEMENTS OF 1st ARRAY : " <<endl;
	for(i=0;i<n;i++)
	{
		int k;
		cin >> k;
		v1.push_back(k);
	}
	print(v1);
	cout << "ENTER SIZE OF 2nd ARRAY : " ;
	cin >> n1;
	cout << "ENTER ELEMENTS OF 2nd ARRAY : " <<endl;
	for(i=0;i<n1;i++)
	{
		int l;
		cin >> l;
		v2.push_back(l);
	}
	print(v2);
	cout << "ENTER THE SUM : ";
	cin >> sum;
	pairwisesum(v1,v2,sum);
	return 0;
}

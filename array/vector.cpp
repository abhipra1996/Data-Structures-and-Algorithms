#include<bits/stdc++.h>
using namespace std;
//#define push_back  pb


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
		cin >> t ;
		a.push_back(t);
	}
	for(i=0;i<n;i++)
	{
		//int t;
		cout << a[i] << " " ;
		//a.push_back(t);
	}
	
	cout <<endl  << "size is : " << a.size();
}

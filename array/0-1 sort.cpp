#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> num)
{
	int l,r;
	l=0;
	r=0;
	for(int i=0;i<num.size();i++)
	{
		if(num[i]==0)
		{
			l++;
			r++;
		}
		else
		{
			num[i]=0;
			r++;
		}
	}
	for(;l<num.size();l++)
	{
		num[l]=1;
	}
	for(int i=0;i<num.size();i++)
	{
	    cout << num[i] << " ";
	}
	    cout << endl;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> num;
		for(int i=0;i<n;i++)
		{
			int k;
			cin >> k;
			num.push_back(k);
		}
	    sort(num);
	    
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

void once(vector<int > &a)
{
	int res=0,x,sum;
	for(int i=0;i<32;i++)
	{
		sum=0;
		x=(1<<i);                     // choosing the bit and the shifting it
		for(int j=0;j<a.size();j++)
		{
			if(a[j] & x)
			{
				sum++;
			}
		}
		if(sum%3)
		{
			res |= x;
		}
	}
	cout << "ONCE OCCURING NUMBER : " << res <<endl ;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int k;
		cin >> k;
		a.push_back(k);
	}
     once(a);
     return 0;
}

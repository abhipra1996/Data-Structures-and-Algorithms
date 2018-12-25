#include<bits/stdc++.h>
using namespace std;

void absminsumpair(vector<int > &a)
{
	int sum=0,min_sum,l,r,min_l,min_r;
	if(a.size()<2)
	{
		cout << "INVALID INPUT" << endl;
		return;
	}
	sort(a.begin(),a.end());
	l=0;
	r=a.size()-1;
	min_l=0;
	min_r=a.size()-1;
	min_sum=a[0]+a[1];
	while(l<r)
	{
		sum=a[l]+a[r];
		if(abs(sum)<abs(min_sum))
		{
			min_sum=sum;
			min_l=l;
			min_r=r;
		}
		if(min_sum<0)
		{
			l++;
		}
		else
		{
			r--;
		}
	}
	cout << a[min_l] << " AND "  << a[min_r] <<endl ;
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
    absminsumpair(a);
	return 0;
}

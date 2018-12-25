#include<bits/stdc++.h>
using namespace std;

void leader(int a[],int n)                     // O(n^2)
{
	int i,j;
	for(i=0;i<n;i++)
	{
	    for(j=i+1;j<n;j++)
	    {
	    	if(a[i]<=a[j])
	    	{
	    		break;
	    	}
	    }
	    if(j==n)
	    {
	    	cout << a[i] << " " ;
	    }
	}
}

void leader2(int a[],int n)                       // right scan when maximum changes it's a leader
{
	int i,j,max;                                  // O(n)
	max=a[n-1];
	cout << max << " " ;
	for(i=n-2;i>=0;i--)
	{
		if(a[i]>max)
		{
			max=a[i] ;
			cout << max << " " ;
		}
	}
}

int main()
{
	int n,i;
	cout << "ENTER SIZE OF ARRAY : ";
	cin >> n;
	cout << "ENTER ELEMENTS OF ARRAY : " <<endl;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	cout << "LEADERS ARE : " ;
	leader2(a,n);
	return 0;
}

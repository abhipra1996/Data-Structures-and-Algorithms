#include<bits/stdc++.h>
using namespace std;

int mcsum(int a[],int n)    //kadanes algorithm //o(n) time and o(1) space
{
	int maxsofar=0,maxbyend=0,start=0,end=0,s=0;
	for(int i=0;i<n;i++)
	{
		maxbyend+=a[i];
		
		if(maxbyend<0)
		{
			maxbyend=0;
			s=s+i;
		}
		else if(maxbyend>maxsofar)
		{
			maxsofar=maxbyend;
			start=s;
			end=i;
		}
	}
	if(maxsofar==0)
	{
		maxsofar=*max_element(a,a+n);
		start=distance(a,max_element(a,a+n));
		end=distance(a,max_element(a,a+n));
	}
	cout << "STARTING INDEX IS : " << start << endl;
	cout << "ENDING INDEX IS :" << end << endl;
	
	return maxsofar;
}

int mcproduct(int a[],int n)
{
	int maxbyend=1,minbyend=1,maxsofar=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
		{
			maxbyend=maxbyend*a[i];
			minbyend=min(minbyend*a[i],1);
		}
		else if(a[i]==0)
		{
			maxbyend=1;
			minbyend=1;
		}
		else
		{
			int temp;
			temp=maxbyend;
			maxbyend=max(minbyend*a[i],1);
			minbyend=temp*a[i];
		}
		if(maxsofar<maxbyend)
		{
			maxsofar=maxbyend;
		}
	}
	return maxsofar; 
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
    int maxsum=0;
    maxsum=mcsum(a,n);
    cout << "MAXIMUM SUM IS : " << maxsum << endl;
    /*
	int maxpro=0;
    maxpro=mcproduct(a,n);
    cout << "MAXIMUM PRODUCT IS : " << maxpro << endl;*/
	return 0;
}

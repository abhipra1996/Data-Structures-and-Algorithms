#include<bits/stdc++.h>
using namespace std;

void reverse(int a[],int n)
{
	int start,end,i,temp;
	start=0;
	end=n-1;
	while(start<end)
	{
		temp=a[start];
		a[start]=a[end];
		a[end]=temp;
		start++;
		end--;
	}
}

void reverserec(int a[],int start ,int end)
{
	int temp=0;
	if(start>=end)
	{
		return ;
	}
	temp=a[start];
	a[start]=a[end];
	a[end]=temp;
	reverserec(a,start+1,end-1);
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
	//reverse(a,n);
	reverserec(a,0,n-1);
	for(i=0;i<n;i++)
	{
		cout <<  a[i] << " ";
	}
	cout << endl ;
	return 0;
}

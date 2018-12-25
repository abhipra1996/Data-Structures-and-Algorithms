#include<bits/stdc++.h>
using namespace std;

void max1subarray(vector<vector<int > > &ori,int m,int n)
{
	vector<vector<int > > sum (m,vector<int>(n,-1));
	int i,j,max=INT_MIN;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==0 || j==0)
			{
				sum[i][j]=ori[i][j];
			}
			else if(ori[i][j]==1)
			{
				sum[i][j]=min(sum[i-1][j-1],min(sum[i-1][j],sum[i][j-1]))+1;
			}
			else if(ori[i][j]==0)
			{
				sum[i][j]=0;
			}
		}
	}
	int maxi,maxj;
	for(i=0;i<m;i++)
	{
	   for(j=0;j<n;j++)
	   {
	   	  if(sum[i][j]>max)
	   	  {
	   	  	max=sum[i][j];
	   	  	maxi=i;
	   	  	maxj=j;
	   	  }
	   }
	}
	for(i=maxi;i>maxi-max;i--)
	{
		for(j=maxj;j>maxj-max;j--)
		{
			cout << ori[i][j] << " ";
		}
		cout << endl;
	}
	
}


int main()
{
	int t;
	while(t--)
	{
		int m,n,i,j,res;
		cin >> m >> n;
		vector<vector<int > > ori;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin >> ori[i][j];
			}
		}
		max1subarray(ori,m,n);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int mincost(vector<vector<int> > &c,vector<vector<int> > &p,int n,int m)
{
	int i,j;
	int dp[n][m][2]; // [0]=right [1]=down
	dp[0][0][0]=dp[0][0][1]=c[0][0];
	
	for(i=1;i<n;i++)
	{
		dp[i][0][0]=dp[i-1][0][1]+c[i][0]+p[i][0];
		dp[i][0][1]=dp[i-1][0][0]+c[i][0];
	}
	for(i=1;i<m;i++)
	{
		dp[0][i][0]=dp[0][i-1][0]+c[0][i];
		dp[0][i][1]=dp[0][i-1][1]+c[0][i]+p[0][i];
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			int mini;
			mini=min(dp[i-1][j][1],dp[i][j-1][0]);
			if(mini==dp[i-1][j][1])
			{
				dp[i][j][1]=dp[i-1][j][1]+c[i][j];
				dp[i][j][0]=dp[i][j][1]+p[i][j];
			}
			else
			{
				dp[i][j][0]=dp[i][j-1][0]+c[i][j];
				dp[i][j][1]=dp[i][j][0]+c[i][j];
			}
		}
	}
	int res;
	res=min(dp[n-1][m-1][0],dp[n-1][m-1][1]);
	return res;
}



int main()
{
	int t;
	cin >> t;
	while(t--)
    {
    	int m,n,i,j;
    	cin >> n >> m ;
    	vector<vector<int> > c,p;
    	for(i=0;i<n;i++)
    	{
    		vector<int> temp;
			for(j=0;j<m;j++)
    		{
    			int k;
    			cin >> k;
    			temp.push_back(k);
			}
			c.push_back(temp);
		}
		
		for(i=0;i<n;i++)
    	{
    		vector<int> temp;
			for(j=0;j<m;j++)
    		{
    			int k;
    			cin >> k;
    			temp.push_back(k);
			}
			p.push_back(temp);
		}
		
		int res;
		res=mincost(c,p,n,m);
		cout << res << endl ;
	}
	return 0;
}

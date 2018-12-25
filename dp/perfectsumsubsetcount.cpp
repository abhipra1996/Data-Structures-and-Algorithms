#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &num,int sum)
{
    int m,n;
    m=num.size();
    n=sum;
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<num[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-num[i-1]];
            }
        }
    }
    return dp[m][n];
}

void solvesubset(vector<int> &num,int sum)
{
	int m,n,i,j;
	m=num.size();
	n=sum;
	bool dp[m+1][n+1];
	vector<vector<int > > res;
	for(i=0;i<=n;i++)
	{
		dp[0][i]=false;
	} 
	for(j=0;j<=m;j++)
	{
		dp[j][0]=true;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j<num[i-1])
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=dp[i-1][j-num[i-1]];
			}
		}
	}
	if(dp[m][n]==false)
	{
		return ;
	}
	cout << "dp solved" << endl;
    
	for(i=m;i>=0;i--)
	{
		if(dp[i][n]==true)
		{
			int r,c;
			vector<int> subset;
			r=i;
			c=n;
			//subset.push_back(num[i-1]);
			while(c>0)
			{	
			      if(dp[r-1][c]!=dp[r][c])
			      {
			      	 subset.push_back(num[r-1]);
			      	 c=c-num[r-1];
			      	 r--;
			      }
			      else
			      {
					  r--;
			      }
			}
			res.push_back(subset);
		}
	}
	cout << res.size() << endl;
	for(i=0;i<res.size();i++)
	{
		for(j=0;j<res[i].size();j++)
		{
			cout << res[i][j] << " " ;
		}
		cout << endl;
	}
	
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,res,sum;
	    vector<int> num;
	    cin >> n;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k ;
	        num.push_back(k);
	    }
	    cin >> sum;
	    //res=solve(num,sum);
	    solvesubset(num,sum);
	    //cout << res << endl;
	}
	return 0;
}

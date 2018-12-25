#include <bits/stdc++.h>
using namespace std;

int knapsack(int w,int n,vector<int> &val,vector<int> &wt)
{
    int dp[n+1][w+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,w,i,res;
	    vector<int> val,wt;
	    cin >> n >> w;
	    for(i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        val.push_back(k);
	    }
	    for(i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        wt.push_back(k);
	    }
	    res=knapsack(w,n,val,wt);
	    cout << res << endl;
	}
	return 0;
}

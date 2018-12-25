#include <bits/stdc++.h>
using namespace std;

int lcs(string x,string y,int m,int n)
{
    //vector<vector<int > > dp(m+1,vector<int>(n+1));
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    /*printing the lcs*/
    string str;
    i=m;
    j=n;
    while(i>0 && j>0)
    {
    	if(x[i-1]==y[j-1])
    	{
    		str.append(x[i-1]);
    		i--;
    		j--;
    	}
    	else if(dp[i-1][j]>dp[i][j-1])
    	{
    		i--;
    	}
    	else
    	{
    		j--;
    	}
    }
    reverse(str.begin(),str.end());
    cout << str << endl;
    return dp[m][n];
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int m,n;
	    cin >> m >> n;
	    string x,y;
	    cin >> x >> y;
	    int res=0;
	    res=lcs(x,y,m,n);
	    cout << res << endl ;
	}
	return 0;
}

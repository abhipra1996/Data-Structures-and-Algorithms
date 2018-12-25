#include <bits/stdc++.h>
using namespace std;

int eggbreak(int n,int k)
{
    int dp[n+1][k+1],i,j,x,res;
    for(i=0;i<=n;i++)
    {
        dp[i][0]=0;
        dp[i][1]=1;
    }
    for(i=1;i<=k;i++)
    {
       // dp[0][i]=0;
        dp[1][i]=i;
    }
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
            for(x=1;x<=j;x++)
            {
                res=1+max(dp[i-1][x-1],dp[i][j-x]);
                if(res<dp[i][j])
                {
                    dp[i][j]=res;
                }
            }
        }
    }
    return dp[n][k];
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,k,res;
	    cin >> n >> k;
	    res=eggbreak(n,k);
	    cout << res << endl;
	}
	return 0;
}

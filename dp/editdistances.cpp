#include<bits/stdc++.h>
using namespace std;

int minDistance(string A, string B) {
    int m,n,i,j;
    m=A.size();
    n=B.size();
    int dp[m+1][n+1];
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0)
            {
                dp[i][j]=j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else if(A[i-1]==B[j-1])
            {
                dp[i][j]=dp[i-1][j-1];   //no modification move forward
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j])); // minimum of insert,delete,modify
            }
        }
    }
    return dp[m][n];
}


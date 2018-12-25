/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete this method*/
int wildCard(string pattern,string str)
{
    int m,n,i,j;
    n=pattern.size();
    m=str.size();
    bool dp[m+1][n+1];
    //memset(dp,false,sizeof(dp));
    dp[0][0]=true;
    for(i=1;i<=n;i++)
    {
        if(pattern[i-1]=='*')
        {
            dp[0][i]=dp[0][i-1];
        }
        else
        {
            dp[0][i]=false;
        }
    }
    for(i=1;i<=m;i++)
    {
        dp[i][0]=false;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if( str[i-1]==pattern[j-1] ||  pattern[j-1]=='?')
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else if(pattern[j-1]=='*')
            {
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
            else
            {
                dp[i][j]=true;
            }
        }
    }
    if(dp[m][n]==true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}

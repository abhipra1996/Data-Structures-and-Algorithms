#include <bits/stdc++.h>
using namespace std;

int lcs(string str1,string str2)
{
    int n,i,j,index;
    n=str1.size();
    int dp[n+1][n+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    index=dp[n][n];
    i=n;
    j=n;
    string temp;
    while(i>=0 && j>=0)
    {
        if(str1[i-1]==str2[j-1])
        {
            temp=temp+str1[i];
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
    cout << temp << endl;
    return dp[n][n];
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string str,rev;
	    int res;
	    cin >> str;
	    rev=str;
	    reverse(rev.begin(),rev.end());
	    res=lcs(str,rev);
	    cout << res << endl;
	}
	return 0;
}

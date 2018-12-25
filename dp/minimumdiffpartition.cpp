#include <bits/stdc++.h>
using namespace std;

int minsumset(vector<int> s)
{
    int i,j,sum=0,n;
    n=s.size();
    for(i=0;i<n;i++)
    {
        sum=sum+s[i];
    }
    bool dp[n+1][sum+1];
    for(i=0;i<=sum;i++)
    {
        dp[0][i]=false;
    }
    for(i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(j<s[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]= dp[i-1][j] || dp[i-1][j-s[i-1]];
            }
        }
    }
    int min=INT_MAX;
    for(i=sum/2;i>=0;i--)
    {
        if(dp[n][i])
        {
            min=i;
            break;
        }
    }
    return sum-(2*min);
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,i;
	    cin >> n;
	    vector<int> s;
	    for(i=0;i<n;i++)
	    {
	        int k;
	        cin >> k ;
	        s.push_back(k);
	    }
	    int res;
	    res=minsumset(s);
	    cout << res << endl ;
	}
	return 0;
}

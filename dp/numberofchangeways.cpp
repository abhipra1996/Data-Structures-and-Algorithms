#include <bits/stdc++.h>
using namespace std;

int change(vector<int> &coin,int value)
{
    int dp[coin.size()+1][value+1],i,j;
    for(i=0;i<=value;i++)
    {
        dp[0][i]=0;
    }
    for(j=0;j<=coin.size();j++)
    {
        dp[j][0]=1;
    }
    for(i=1;i<=coin.size();i++)
    {
        for(j=1;j<=value;j++)
        {
            if(j<coin[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
            }
        }
    }
    return dp[coin.size()][value];
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,value,res;
	    cin >> n ;
	    vector<int> coin;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        coin.push_back(k);
	    }
	    cin >> value ; 
	    res=change(coin,value);
	    cout << res << endl ;
	}
	return 0;
}

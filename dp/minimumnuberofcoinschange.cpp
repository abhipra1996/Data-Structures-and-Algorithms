#include <bits/stdc++.h>
using namespace std;
int mincoin(vector<int> &coin,int v)
{
    int m,n,i,j;
    m=coin.size();
    n=v;
    int dp[n+1];
    for(i=0;i<=n;i++)
    {
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(i=1;i<=v;i++)
    {
        for(j=0;j<m;j++)
        {
            if(coin[j]<=i)
            {
                int subres=dp[i-coin[j]];
                if(subres!=INT_MAX && subres+1<dp[i])
                {
                    dp[i]=subres+1;
                }
            }
        }
    }
    if(dp[n]==INT_MAX)
    {
        return -1;
    }
    else
    {
        return dp[n];
    }
    
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int v,n,res;
	    cin >> v >> n;
	    vector<int> coin;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        coin.push_back(k);
	    }
	    sort(coin.begin(),coin.end());
	    res=mincoin(coin,v);
	    cout << res << endl;
	}
	return 0;
}

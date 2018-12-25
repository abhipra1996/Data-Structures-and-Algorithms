#include <bits/stdc++.h>
using namespace std;
//O(n*r)
long long int bino(long long int n,long long int r)
{
    if(r>n)
    {
        return 0;
    }
    long long int dp[n+1][r+1];
    long long int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=min(i,r);j++)
        {
            if(j==0 || j==i)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]) % 1000000007;
            }
        }
    }
    return dp[n][r];
}

//O(r)
long long int binoeffe(long long int n,long long int r)
{
	if(r<n-r)
	{
		r=n-r;
	}
	long long int res=1;
	for(int i=0;i<r;i++)
	{
		res=res*(n-i);
		res=res/(i+1);
	}
	return res;
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    long long int n,r,res;
	    cin >> n >> r;
	    res=bino(n,r);
	    cout << res << endl;
	}
	return 0;
}

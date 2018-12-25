#include <iostream>
using namespace std;

long long int tile(long long int n)
{
    long long int dp[n+1],i;
    dp[1]=1;
    dp[2]=2;
    for(i=2;i<n;i++)
    {
        dp[i+1]=dp[i]+dp[i-1];
    }
    return dp[n];
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    long long int n,res;
	    cin >> n ;
	    res=tile(n);
	    cout << res << endl;
	}
	return 0;
}

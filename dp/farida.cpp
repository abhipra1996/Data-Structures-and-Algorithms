#include<bits/stdc++.h>
using namespace std;

long long int solve(vector<long long int> &num)
{
	long long int i,n;
	n=num.size();
	long long int dp[n];
	dp[0]=num[0];
	if(num[1]>=num[0])
	{
		dp[1]=num[1];
	}
	else
	{
		dp[1]=num[0];
	}
	for(i=2;i<n;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+num[i]);
	}
	return dp[n-1];
}

int main()
{
	int t,o;
	o=1;
	cin >> t;
	while(t--)
	{
	   int i,j,n;
	   cin >> n;
	   vector<long long int> num;
	   for(i=0;i<n;i++)
	   {
	   	 long long int k;
	   	 cin >> k ;
	   	 num.push_back(k);
	   }	
	   long long int res=0;
	   if(n!=0)
	   {
	   	 res=solve(num);
	   }
	   cout << "Case " << o <<": " << res << endl;
	   o++;	
	}
}

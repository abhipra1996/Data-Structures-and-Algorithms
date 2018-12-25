#include <bits/stdc++.h>
using namespace std;

int maxsum(vector<int> &num)
{
    int m,i,j;
    m=num.size();
    int dp[m];
    for(int i=0;i<m;i++)
    {
        dp[i]=num[i];
    }
    for(i=1;i<m;i++)
    {
        for(j=0;j<i;j++)
        {
            if(num[j]<num[i])
            {
                dp[i]=max(dp[i],num[i]+dp[j]);
            }
        }
    }
    int max=INT_MIN;
    for(i=0;i<m;i++)
    {
        if(dp[i]>max)
        {
            max=dp[i];
        }
    }
    return max;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,res;
	    cin >> n;
	    vector<int> num;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        num.push_back(k);
	    }
	    res=maxsum(num);
	    cout << res << endl;
	}
	return 0;
}

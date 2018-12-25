#include <bits/stdc++.h>
using namespace std;

int lcsub(string str1,string str2)
{
    int i,j,res;
    int dp[str1.size()+1][str2.size()+1];
    res=0;
    for(i=0;i<=str1.size();i++)
    {
        for(j=0;j<=str2.size();j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                res=max(res,dp[i][j]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    return res;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n1,n2,res;
	    cin >> n1 >> n2;
	    string str1,str2;
	    cin >> str1 >> str2;
	    res=lcsub(str1,str2);
	    cout << res << endl;
	}
	return 0;
}

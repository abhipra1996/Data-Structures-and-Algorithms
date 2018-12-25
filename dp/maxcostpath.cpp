#include <bits/stdc++.h>
using namespace std;

long long int maxpath(vector<vector<int> > &mat)
{
    int n,i,j;
    n=mat.size();
    //cout << n << endl;
    long long int dp[n][n];
    //memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
    {
        dp[n-1][i]=mat[n-1][i];
    }
    for(int row=n-2;row>=0;row--)
    {
        for(int col=0;col<n;col++)
        {
            int down=0,rightdown=0,leftdown=0;
            
            down=dp[row+1][col];
           
           
            if(col!=0)
            {
                leftdown=dp[row+1][col-1];
            }
           
            if(col!=n-1)
            {
                rightdown=dp[row+1][col+1];
            }
            
            dp[row][col]=mat[row][col]+max(down,max(leftdown,rightdown));
        }
    }
    long long int max=dp[0][0];
    for(i=1;i<n;i++)
    {
        if(dp[0][i]>max)
        {
            max=dp[0][i];
        }
    }
    return max;
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,i,j;
	    cin >> n;
	    vector<vector<int> > mat;
	    for(i=0;i<n;i++)
	    {
	        vector<int> temp;
	        for(j=0;j<n;j++)
	        {
	            int k;
	            cin >> k;
	            //cout << k << " ";
	            temp.push_back(k);
	        }
	        //cout << endl ;
	        mat.push_back(temp);
	    }
	    long long int res=0;
	    res=maxpath(mat);
	    cout << res << endl;
	}
	return 0;
}

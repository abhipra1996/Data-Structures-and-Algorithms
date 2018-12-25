#include <bits/stdc++.h>
using namespace std;

int maxgold(vector<vector<int> > &mine,int n,int m)
{
    //int i,j;
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    for(int col=m-1;col>=0;col--)
    {
        for(int row=0;row<n;row++)
        {
            int right=0,righttop=0,rightbottom=0;
            if(col==m-1)
            {
                right=0;
            }
            else
            {
                right=dp[row][col+1];
            }
            if(col==m-1 || row==0)
            {
                righttop=0;
            }
            else
            {
                righttop=dp[row-1][col+1];
            }
            if(col==m-1 || row==n-1)
            {
                rightbottom=0;
            }
            else
            {
                rightbottom=dp[row+1][col+1];
            }
            
            dp[row][col]=mine[row][col]+max(right,max(rightbottom,righttop)); 
        }
    }
    int max=dp[0][0];
    for(int i=1;i<n;i++)
    {
        if(dp[i][0]>max)
        {
            max=dp[i][0];
        }
    }
    return max;
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,m,i,j;
	    cin >> n >> m;
	    vector<vector<int > > mine;
	    for(i=0;i<n;i++)
	    {
	        vector<int> temp;
	        for(j=0;j<m;j++)
	        {
	            int k;
	            cin >> k;
	            temp.push_back(k);
	        }
	        mine.push_back(temp);
	    }
	    int res=0;
	    res=maxgold(mine,n,m);
	    cout << res << endl;
	}
	return 0;
}

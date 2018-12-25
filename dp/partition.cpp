#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &a)
{
	for(int i=0;i<a.size();i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
/*
void printset(vector<int> &num,int i,int sum,vector<int> &p,int k,int dp[][k])
{
	if(i==0 && sum!=0 && dp[0][sum])
	{
		p.push_back(num[i]);
		display(p);
		return;
	}
	
	if(i==0 && sum==0)
	{
		display(p);
		return;
	}
	if(dp[i-1][sum])
	{
		vector<int> b;
		b=p;
		printset(num,i-1,sum,b,k,dp);
	}
	if(num[i]<=sum &&  dp[i-1][sum-num[i]])
	{
		p.push_back(num[i]);
		printset(num,i-1,sum-num[i],p,k,dp);
	}
}
*/

bool partition(vector<int> num)
{
    int i,sum=0;
    for(i=0;i<num.size();i++)
    {
        sum=sum+num[i];
    }
    if(sum%2==1)
    {
        return false;
    }
    bool dp[num.size()+1][(sum/2)+1];
    for(i=0;i<=(sum/2);i++)
    {
        dp[0][i]=false;
    }
    for(i=0;i<=num.size();i++)
    {
        dp[i][0]=true;
    }
    for(i=1;i<=num.size();i++)
    {
        for(int j=1;j<=(sum/2);j++)
        {
            if(j<num[i-1])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=(dp[i-1][j] || dp[i-1][j-num[i-1]]);
            }
        }
    }
    vector<int> p;
    //printset(num,num.size()-1,(sum/2),p,(sum/2)+1),dp);
    
    return dp[num.size()][(sum/2)];
    
    
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,i;
	    cin >> n;
	    vector<int> num;
	    for(i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        num.push_back(k);
	    }
	    bool res=false;
	    res=partition(num);
	    if(res==true)
	    {
	        cout << "YES" << endl;
	    }
	    else
	    {
	        cout << "NO" << endl;
	    }
	}
	return 0;
}

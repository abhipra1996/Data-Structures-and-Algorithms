#include <bits/stdc++.h>
using namespace std;

bool indict(vector<string> &dict,string q)
{
    int i,n;
    n=dict.size();
    for(i=0;i<n;i++)
    {
        if(dict[i].compare(q)==0)
        {
            return true;
        }
    }
    return false;
}

int solve(string q,vector<string> &dict)
{
    int i,j,n;
    n=q.size();
    bool dp[n+1];
    for(i=0;i<=n;i++)
    {
        dp[i]=false;
    }
    //memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        if(dp[i]==false && indict(dict,q.substr(0,i)))
        {
            dp[i]=true;
        }
        
        if(dp[i]==true)
        {
            if(i==n)
            {
                return 1;
            }
            for(j=i+1;j<=n;j++)
            {
                if(dp[j]==false && indict(dict,q.substr(i,j-i)) )
                {
                    dp[j]=true;
                }
                
                if(j==n && dp[j]==true)
                {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,i;
	    vector<string> dict;
	    string query;
	    cin >> n;
	    for(i=0;i<n;i++)
	    {
	        string temp;
	        cin >> temp;
	        dict.push_back(temp);
	    }
	    cin >> query ;
	    int res=0;
	    if(query.size()!=0)
	    {
	        res=solve(query,dict);
	    }
	    cout << res << endl ;
	}
	return 0;
}

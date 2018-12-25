/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/
bool mycomp(pair<int,int> &p1,pair<int,int> &p2)
{
    if(p1.first<p2.first)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int maxChainLen(struct val p[],int n)
{
    int dp[n+1],i,j;
    vector<pair<int,int > > pt;
    for(i=0;i<n;i++)
    {
        pair<int,int> temp;
        temp.first=p[i].first;
        temp.second=p[i].second;
        //cout << temp.first << " " <<temp.second << endl;
        pt.push_back(temp);
    }
    sort(pt.begin(),pt.end(),mycomp);
    for(i=0;i<=n;i++)
    {
        dp[i]=1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(pt[i].first>pt[j].second && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    int max=INT_MIN;
    for(i=0;i<n;i++)
    {
        if(dp[i]>max)
        {
            max=dp[i];
        }
    }
    return max;
   
}

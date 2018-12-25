
// height,length,width;
bool comp(vector<int> a,vector<int> b)
{
    int l1,l2,w1,w2;
    l1=a[1];
    l2=b[1];
    w1=a[2];
    w2=b[2];
    if( (l1*w1) > (l2*w2) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
int maxHeight(int height[],int width[],int length[],int n)
{
    vector<vector<int> > box;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        vector<int> temp;
        temp.push_back(height[i]);
        temp.push_back(length[i]);
        temp.push_back(width[i]);
        
        box.push_back(temp);
        
        vector<int> temp1;
        temp1.push_back(length[i]);
        temp1.push_back(max(width[i],height[i]));
        temp1.push_back(min(width[i],height[i]));
        
        box.push_back(temp1);
        
        vector<int> temp2;
        temp2.push_back(width[i]);
        temp2.push_back(max(length[i],height[i]));
        temp2.push_back(min(length[i],height[i]));
        
        box.push_back(temp2);
    }
    sort(box.begin(),box.end(),comp);
    int dp[box.size()];
    for(i=0;i<box.size();i++)
    {
        dp[i]=box[i][0];
    }
    for(i=1;i<box.size();i++)
    {
        for(j=0;j<i;j++)
        {
            if( box[i][1] < box[j][1] && box[i][2] < box[j][2] )
            {
                dp[i]=max(dp[i],dp[j]+box[i][0]);
            }
        }
    }
    int max=INT_MIN;
    for(i=0;i<box.size();i++)
    {
        if(dp[i]>max)
        {
            max=dp[i];
        }
    }
    return max;
}

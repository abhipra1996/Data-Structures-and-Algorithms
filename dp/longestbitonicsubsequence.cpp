int longestSubsequenceLength(const vector<int> &A) {
    
    vector<int> lis(A.size(),1);
    vector<int> lds(A.size(),1);
    int i,j,n,max;
    n=A.size();
    if(n==0 || n==1)
    {
        return n;
    }
    //LIS
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(A[i]>A[j] && lis[i]<lis[j]+1 )
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    //LDS
    for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
        {
            if(A[i]>A[j] && lds[i]<lds[j]+1)
            {
                lds[i]=lds[j]+1;
            }
        }
    }
    max=lis[0]+lds[0]-1;
    for(i=1;i<n;i++)
    {
        if(lis[i]+lds[i]-1>max)
        {
            max=lis[i]+lds[i]-1;
        }
       
    }
    return max;
    
}


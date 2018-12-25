int maxhist(vector<int> A,int c)
{
    stack<int> st;
    int tp,maxarea=0,area=0,i=0;
    while(i<c)
    {
        if(st.empty() || A[i]>=A[st.top()])
        {
            st.push(i++);
        }
        else
        {
            tp=st.top();
            st.pop();
            area= A[tp] * i;
            if(!st.empty())
            {
                area=A[tp] * (i-st.top()-1);
            }
            maxarea=max(area,maxarea);
        }
    }
    while(!st.empty())
    {
        tp=st.top();
        st.pop();
        area= A[tp] * i;
        if(!st.empty())
        {
            area=A[tp] * (i-st.top()-1);
        }
        maxarea=max(area,maxarea);
    }
    return maxarea;
}

int maximalRectangle(vector<vector<int> > &A) {
    int m,n;
    m=A.size();  //rowcount 
    n=A[0].size(); //columncount
    vector<vector<int > > sum (m,vector<int>(n));
    int maxarea=0;
    maxarea=maxhist(A[0],n);
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==1)
            {
                A[i][j]+=A[i-1][j];
            }
            maxarea=max(maxarea,maxhist(A[i],n));
        }
    }
    return maxarea;
	
}


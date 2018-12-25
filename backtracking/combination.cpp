void sol(vector<int> &A,int n,int k,int index,vector<int> &data,int i,vector<vector<int > > &v)
{
    if(index==k)
    {
        v.push_back(data);
        return;
    }
    if(i>=n)
    {
        return;
    }
    data[index]=A[i];
    sol(A,n,k,index+1,data,i+1,v);
    sol(A,n,k,index,data,i+1,v);
}


vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int > > res;
    vector<int> A;
    vector<int> data(k);
    for(int i=1;i<=n;i++)
    {
        A.push_back(i);
    }
    sol(A,n,k,0,data,0,res);
    return res;
}


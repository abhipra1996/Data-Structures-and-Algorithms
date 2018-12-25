vector<vector<int> > subsets(vector<int> &A) {
    vector<vector<int> > res;
    vector<int> temp;
    int n;
    n=A.size();
    //res.push_back(temp);
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if( (i & (1<<j) ) > 0)
            {
                temp.push_back(A[j]);
            }
        }
        sort(temp.begin(),temp.end());
        res.push_back(temp);
        temp.clear();
    }
    sort(res.begin(),res.end());
    return res;
}


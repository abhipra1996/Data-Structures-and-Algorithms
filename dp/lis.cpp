int lis(const vector<int> &A) {
       vector<int> lis(A.size(),1);
       int i,j,max,n;
       n=A.size();
       for(i=1;i<n;i++)
       {
           for(j=0;j<i;j++)
           {
               if(A[i]>A[j] && lis[i]<lis[j]+1)
               {
                   lis[i]=lis[j]+1;
               }
           }
       }
       max=INT_MIN;
       for(i=0;i<n;i++)
       {
           if(lis[i]>max)
           {
               max=lis[i];
           }
       }
       return max;
}


string Solution::longestPalindrome(string A) {
   int n,i,j,k;
   n=A.size();
   bool dp[n][n];
   memset(dp,0,sizeof(dp));
   for(i=0;i<n;i++)
   {
       dp[i][i]=true;
   }
   int start=0,maxlength=1;
   for(i=0;i<n-1;i++)
   {
       if(A[i]==A[i+1])
       {
           dp[i][i+1]=true;
           start=i;
           maxlength=2;
       }
   }
   for(k=3;k<=n;k++)
   {
       for(j=0;j<n-k+1;j++)
       {
           int l;
           l=j+k-1;
           if(A[j]==A[l] && dp[j+1][l-1]==true)
           {
               dp[j][l]=true;
               if(k>maxlength)
               {
                   start=j;
                   maxlength=k;
               }
           }
       }
   }
   
   string res;
   res=A.substr(start,maxlength);
   return res;
   
}


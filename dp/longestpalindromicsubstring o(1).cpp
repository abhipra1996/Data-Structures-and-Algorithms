string Solution::longestPalindrome(string A) {
   int n,i,j,k;
   n=A.size();
   int low,high,maxlength=1,start=0;
   for(i=1;i<n;i++)
   {
       low=i-1;
       high=i;
       while(low>=0 && high<n && A[low]==A[high])
       {
           if(high-low+1>maxlength)
           {
               start=low;
               maxlength=high-low+1;
           }
           low--;
           high++;
       }
       
       low=i-1;
       high=i+1;
       while(low>=0 && high<n && A[low]==A[high])
       {
           if(high-low+1>maxlength)
           {
               start=low;
               maxlength=high-low+1;
           }
           low--;
           high++;
       }
   }
   
   string res;
   res=A.substr(start,maxlength);
   return res;
   
}


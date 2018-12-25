/*You are required to complete this method*/
int maxLen(int arr[], int n)
{
     int end,sum,maxlen,i;
     end=-1;
     sum=0;
     maxlen=0;
     unordered_map<int, int> map;
      for(i=0;i<n;i++)
      {
          if(arr[i]==0)
          {
              arr[i]=-1;
          }
      }
      for(i=0;i<n;i++)
      {
          sum=sum+arr[i];
          if(sum==0)
          {
              maxlen=i+1;
              end=i;
          }
          if(map.find(sum+n)!=map.end())
          {
              if(maxlen < i-map[sum+n])
              {
                  maxlen=i-map[sum+n];
                  end=i;
              }
          }
          else
          {
              map[sum+n]=i;
          }
      }
      for(i=0;i<n;i++)
      {
          if(arr[i]==-1)
          {
              arr[i]=0;
          }
      }
     return maxlen;
}

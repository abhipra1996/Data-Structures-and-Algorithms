int searchpeak(int arr[],int low,int high,int n)
{
    if(high>=low)
    {
        int mid;
        mid=(low+high)/2;
        //mid=(low+(high-low))/2;
        if( (mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]) )
        {
            return mid;
        }
        else if(mid >0 && arr[mid-1]>arr[mid])
        {
            return searchpeak(arr,low,mid-1,n);
        }
        else
        {
            return searchpeak(arr,mid+1,high,n);
        }
    }
    return -1;
}

int peak(int arr[], int n)
{
   return searchpeak(arr,0,n-1,n);
}

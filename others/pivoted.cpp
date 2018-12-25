#include <iostream>
using namespace std;

int search(int a[],int low,int high,int num)
{
    int mid;
      if(high < low)
   { 
       return -1;
   }
    mid = (low+high)/2;
    if(a[mid] == num)
    {
       // cout<<a[mid];
        return mid;
    }
    else if(a[mid]<num)
    {
        return search(a,(mid+1),high,num);
    }
    else{
        return search(a,low,mid-1,num);
    }
   // return -1;
    
}
int main() {
    int t;
    cin>>t;
    while(t>0)
    {
        int i,j,num,*a,n,ff;
        cin>>n;
        a = new int [n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>num;
        
        for(i=0;i<n-1;i++)
        {
        if(a[i] > a[i+1])
        {
            break;
        }
        }
       
        if(i == n-2)
        {
            ff=search(a,0,n-1,num);
            cout<<ff<<endl;
           
        }
        else if(a[i]>=num && a[0]<=num)
        {
        	ff=search(a,0,i,num);
        	cout << ff << endl;
        }
        else
        {
        	ff=search(a,i+1,n-1,num);
        	cout << ff << endl;
        }
	t--;
    }
	return 0;
}

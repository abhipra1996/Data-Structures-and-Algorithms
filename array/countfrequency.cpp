#include <bits/stdc++.h>
using namespace std;

int first(vector<int > &a,int low,int high,int x,int n)
{
    if(high>=low)
    {
        int mid=0;
        mid=(low+high)/2;
        if((mid==0 || x>a[mid-1]) && a[mid]==x)
        {
            return mid;
        }
        else if(x>a[mid])
        {
            return first(a,mid+1,high,x,n);
        }
        else
        {
            return first(a,low,mid-1,x,n);
        }
    }
    return -1;
}

int last(vector<int> &a,int low,int high,int x,int n)
{
    if(high>=low)
    {
        int mid=0;
        mid=(low+high)/2;
        if((mid==n-1 || x<a[mid+1] ) && a[mid]==x)
        {
            return mid;
        }
        else if(x<a[mid])
        {
            return last(a,low,mid-1,x,n);
        }
        else
        {
            return last(a,mid+1,high,x,n);
        }
    }
    return -1;
}
int sol(vector<int > &a,int x,int n)
{
    int i,j;
    i=first(a,0,n-1,x,n);
    cout << i << " "<<" ";
    if(i==-1)
    {
        return i;
    }
    j=last(a,i,n-1,x,n);
    cout << j << " " << endl;
    return j-i+1;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,x;
	    cin >> n >> x;
	    vector<int> a;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        a.push_back(k);
	    }
	    int count=0;
	    count=sol(a,x,n);
	    cout << count << endl;
	}
	return 0;
}

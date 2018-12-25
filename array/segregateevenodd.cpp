#include <bits/stdc++.h>
using namespace std;

void segregate(vector<int > &a)
{
    int l,r;
    l=0;
    r=a.size()-1;
    while(l<r)
    {
          while(l<r && (a[l]%2==0))
          {
             l++;
          }
          while(l<r && (a[r]%2==1))
          {
              r--;
          }
          if(l<r)
          {
             int temp;
			 temp=a[l];
             a[l]=a[r];
             a[r]=temp;
             l++;
             r--;
    }
    }
    for(int i=0;i<a.size();i++)
    {
        cout << a[i];
    }
    cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    vector<int > a;
	    cin >> n;
	    for(int i=0;i<n;i++)
	    {
	        int j;
	        cin >> j;
	        a.push_back(j);
	    }
	    segregate(a);
	}
	return 0;
}

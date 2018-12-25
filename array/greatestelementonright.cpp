#include <iostream>
#include <vector>
using namespace std;
void ge(vector<int > &a)
{
    int max,n,i;
    n=a.size();
    max=a[n-1];
    a[n-1]=-1;
    for(i=n-2;i>=0;i--)
    {
        int temp;
        temp=a[i];
        a[i]=max;  
        if(temp>max)
        {
            max=temp;
        }
         
        
    }
    for(i=0;i<n;i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;
    
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int > a;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        a.push_back(k);
	    }
	    ge(a);
	}
	return 0;
}

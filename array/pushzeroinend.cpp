#include <bits/stdc++.h>
using namespace std;
void pushzero(vector<int> &a)
{
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=0)
        {
            a[count++]=a[i];
        }
    }
    while(count<a.size())
    {
        a[count++]=0;
    }
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl ;
}

int main() {
	int t;
	cin >>t;
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
	    pushzero(a);
	}
	return 0;
}

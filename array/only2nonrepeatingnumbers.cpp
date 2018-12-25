#include <bits/stdc++.h>
using namespace std;

void sol(vector<int > &a)
{
    int xor2,x,y,i,setbit;
    xor2=a[0];
    x=0;
    y=0;
    for(i=1;i<a.size();i++)
    {
        xor2=xor2^a[i];
    }
    setbit= (xor2) & ~(xor2-1);
    for(i=0;i<a.size();i++)
    {
        if(a[i]&setbit)
        {
            x=x^a[i];
        }
        else
        {
            y=y^a[i];
        }
    }
    if(x>y)
    {
        cout << x << " " << y << endl;
    }
    else
    {
        cout << y << " " << x << endl;
    }
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int> a;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        a.push_back(k);
	    }
	    sol(a);
	}
	return 0;
}

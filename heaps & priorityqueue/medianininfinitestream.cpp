#include <bits/stdc++.h>
using namespace std;

priority_queue<long long int> lo;
priority_queue<long long int,vector<long long int>,greater<long long int> > hi;


void add(long long int num)
{
    lo.push(num);
    
    hi.push(lo.top());
    lo.pop();
    
    if(hi.size()>lo.size())
    {
        lo.push(hi.top());
        hi.pop();
    }
}

long long int median()
{
    long long int res;
    if(lo.size()>hi.size())
    {
        res=lo.top();
    }
    else
    {
        res=(lo.top()+hi.top())/2;
    }
    return res;
}


int main() {
	int n;
	cin >> n ;
	while(n--)
	{
	    long long int x;
	    cin >> x;
	    add(x);
	    cout << median() << endl;
	}
	
	
	return 0;
}

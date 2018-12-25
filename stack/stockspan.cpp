#include <bits/stdc++.h>
using namespace std;

void stspan(vector<int> &a)
{
	stack<int> st;
	vector<int> sp(a.size());
	//sp[0]=1;
	for(int i=0;i<a.size();i++)
	{
		while(!st.empty() && a[i]>a[st.top()])
		{
			st.pop();
		}
		if(st.empty())
		{
			st.push(-1);
		}
		sp[i]=i-st.top();
		st.push(i);
	}
	
	for(int i=0;i<a.size();i++)
	{
		cout << sp[i] << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,i;
	    cin >> n;
	    vector<int> span;
	    for(i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        span.push_back(k);
	    }
	    stspan(span);
	}
	return 0;
}

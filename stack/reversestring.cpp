#include<bits/stdc++.h>
using namespace std;

string reverse(string s)
{
	stack<char> st;
	string r;
	for(int i=0;i<s.size();i++)
	{
		st.push(s[i]);
	}
	while(!st.empty())
	{
		char k;
		k=st.top();
		st.pop();
		r.push_back(k);
	}
	return r;
}

int main()
{
	string s,r;
	cin >> s;
	r=reverse(s);
	cout << r <<endl;
	return 0;
}

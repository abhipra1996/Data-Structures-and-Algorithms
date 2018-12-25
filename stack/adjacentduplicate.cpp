#include<bits/stdc++.h>
using namespace std;

void adjacentduplicates(string &str)
{
	stack<char> st;
	string res;
	st.push(str[0]);
	for(int i=1;i<str.length();i++)
	{
		if(st.top()==str[i])
		{
			st.pop();
		}
		else
		{
			st.push(str[i]);
		}
	}
	while(!st.empty())
	{
		char temp;
		temp=st.top();
		st.pop();
		res=res+temp;
	}
	reverse(res.begin(),res.end());
	cout << res << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		adjacentduplicates(str);
	}
	return 0;
}

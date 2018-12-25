#include <bits/stdc++.h>
using namespace std;

int lvss(string str)
{
    int n,i,longest=0;
    stack<int> st;
    n=str.length();
    st.push(-1);
    for(i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if(!st.empty())
            {
                longest=max(longest,i-st.top());
            }
            else
            {
                st.push(i);
            }
            
        }
    }
    return longest;
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    int res;
	    res=lvss(str);
	    cout << res << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int minreversal(string str)
{
    int n,i;
    n=str.length();
    if(n%2)
    {
        return -1;
    }
    stack<char> st;
    for(i=0;i<n;i++)
    {
        if(str[i]=='}' && !st.empty())
        {
            if(st.top()=='{')
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
        else
        {
            st.push(str[i]);
        }
    }
    int redlen,m=0;
    redlen=st.size();
    while(!st.empty() && st.top()=='{')
    {
        st.pop();
        m++;
    }
    return ((redlen/2)+(m%2));
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    int res;
	    res=minreversal(str);
	    cout << res << endl;
	}
	return 0;
}

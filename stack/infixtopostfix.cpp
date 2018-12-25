#include <bits/stdc++.h>
using namespace std;

bool isoperand(char c)
{
    if(c >= 'a' && c<='z' || c>='A' && c<='Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int pre(char c)
{
    switch(c){
        case'+':
        case '-':return 1;
                
        case '*':
        case '/' :return 2;
                  
        case '^' : return 3;
                
        default : return -1;
    }
}

string infixtopostfix(string str)
{
    stack<char> st;
    string res;
    int n,i;
    n=str.length();
    for(i=0;i<n;i++)
    {
        if(isoperand(str[i]))
        {
            res=res+str[i];
        }
        else if(str[i]=='(')
        {
            st.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res=res+st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && pre(str[i])<=pre(st.top()))
            {
                   res=res+st.top();
                   st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty())
    {
        res=res+st.top();
        st.pop();
    }
    return res;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string str,ans;
	    cin >> str;
	    ans=infixtopostfix(str);
	    cout << ans << endl;
	}
	return 0;
}

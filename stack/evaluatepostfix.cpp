#include <bits/stdc++.h>
using namespace std;

void evaluate(string str)
{
    stack<char> st;
    int i,n;
    n=str.length();
    for(i=0;i<n;i++)
    {
        if(isdigit(str[i]))
        {
            st.push(str[i]-'0');
        }
        else
        {
            int num1=st.top();
            st.pop();
            int num2=st.top();
            st.pop();
            switch(str[i])
            {
                case '+' : st.push(num2+num1);
                           break;
                case '-' : st.push(num2-num1);
                        break;
                case '*' : st.push(num2*num1);
                          break;
                case '/' : st.push(num2/num1);
                           break;
            }
        }
    }
    int ans;
    ans=st.top();
    st.pop();
    cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    evaluate(str);
	}
	return 0;
}

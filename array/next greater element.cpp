#include <bits/stdc++.h>
using namespace std;

void nge(vector<int> &a)
{
    stack<int> st;
    map<int,int> table;
    int next,temp;
    st.push(a[0]);
    for(int i=1;i<a.size();i++)
    {
        next=a[i];
        if(st.empty()==false)
        {
            temp=st.top();
            st.pop();
            while(temp<next)
            {
                table[temp]=next;
				//cout << next << " ";
                if(st.empty())
                {
                   break; 
                }
                temp=st.top();
                st.pop();
            }
            if(temp>next)
            {
                st.push(temp);
            }
        }
        st.push(next);
    }
    while(st.empty()==false)
    {
        temp=st.top();
		st.pop();
		next=-1;
		table[temp]=next;
        //cout << next << " ";
    }
    for(int i=0;i<a.size();i++)
    {
    	int val;
    	val=table.at(a[i]);
    	cout << val << " ";
    }
    cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int > a;
	    //cout << "n= " << n << endl;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	      //  cout << "element = " << k ;
	        a.push_back(k);
	    }
	    nge(a);
	}
	return 0;
}

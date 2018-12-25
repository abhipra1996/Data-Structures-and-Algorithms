#include <bits/stdc++.h>
using namespace std;

void swap(char *a,char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void allpermute(string str,int left,int right,vector<string> &v)
{
    if(left==right)
    {
        //cout << str << " ";
        v.push_back(str);
    }
    else
    {
        for(int i=left;i<=right;i++)
        {
            swap(str[left],str[i]);
            allpermute(str,left+1,right,v);
            swap(str[left],str[i]);
        }
    }
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    vector<string> v;
	    allpermute(str,0,str.size()-1,v);
	    sort(v.begin(),v.end());
	    for(int i=0;i<v.size();i++)
	    {
	        cout << v[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}

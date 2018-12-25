#include<bits/stdc++.h>
using namespace std;

bool comp(string a,string b)
{
	return a.size()>b.size();
}

void combination(string ori,string str,int depth,int start,vector<string> &res)
{
	int len,i;
	len=ori.size();
	for(i=start;i<len;i++)
	{
		str[depth]=ori[i];
		res.push_back(str);
		if(i<len-1)
		{
			combination(ori,str,depth+1,start+1,res);
		}
	}
}


int main()
{
	string s;
	cin >> s;
	string str(s.size(),' ');
	vector<string> res;
	combination(s,str,0,0,res);
	//sort(res.begin(),res.end(),comp);
	for(int i=0;i<res.size();i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}

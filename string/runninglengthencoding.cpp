#include<bits/stdc++.h>
using namespace std;

string ren(string str)
{
  int len,i,j=0;
  len=str.size();
  string res;
  int last;
  last=0;
  int count=1;
 // bool changed=false;
  for(i=1;i<len;i++)
  {
        if(str[i]==str[last])
      {
          count++;
      }
      else
      {
        res=res+str[last];
		res+=to_string(count);
		last=i;
        count=1;
      }
  }
  res=res+str[last];
  res+=to_string(count);
  //cout << res << endl;
  return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str,res;
		cin >> str;
		res=ren(str);
		cout << res << endl;
	}
}

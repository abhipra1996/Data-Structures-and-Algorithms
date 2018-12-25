#include <bits/stdc++.h>
using namespace std;

void sumsubarray(vector<int > &a,int sum)
{
    int sumsofar,start=0,i,end;
    sumsofar=a[0];
    for(i=1;i<=a.size();i++)
    {
        while(sumsofar>sum && start<i-1)
        {
            sumsofar=sumsofar-a[start];
            start++;
        }
        if(sumsofar==sum)
        {
            end=i-1;
            cout << start+1 << " " << end+1 <<endl;
            return ;
        }
        if(i<a.size())
        {
            sumsofar+=a[i];
        }
    }
    cout << "-1" << endl;
    return ;
}

void sumsubarrayneg(vector<int > &a,int sum)
{
	int sumsofar=0;
	unordered_map<int, int> table;
	for(int i=0;i<a.size();i++)
	{
		sumsofar+=a[i];
		if(sumsofar==sum)
		{
			cout << "0 " << i-1 << endl;
			return ;
		}
		if(table.find(sumsofar-sum)!=table.end())
		{
			cout << table[sumsofar-sum]+1 << " " << i-1 << endl;
			return ;
		}
		table[sumsofar]=i;
	}
	cout << "-1" ;
	return ;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,sum;
	    cin >> n >> sum;
	    vector<int > a;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        a.push_back(k);
	    }
	    sumsubarrayneg(a,sum);
	}
	return 0;
}

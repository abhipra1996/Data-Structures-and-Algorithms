#include<bits/stdc++.h>
using namespace std;

vector<int> slidingmaximum(const vector<int> &A, int B) {
    int n,i;
    vector<int> res;
    n=A.size();
    if(B>n)
    {
        int max;
        max=*max_element(A.begin(),A.end());
        res.push_back(max);
        return res;
    }
    deque<int> q(B);
    for(i=0;i<B;i++)
    {
        while(!q.empty() && A[i]>=A[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<n;i++)
    {
        res.push_back(A[q.front()]);
        
        while(!q.empty() && q.front()<=i-B)
        {
            q.pop_front();
        }
        
        while(!q.empty() && A[i]>=A[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    res.push_back(A[q.front()]);
    return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,w;
		cin >> n >> w;
		vector<int> a,res;
		for(int i=0;i<n;i++)
		{
			int k;
			cin >> k;
			a.push_back(k);
		}
		res=slidingmaximum(a,w);
		for(int i=0;i<res.size();i++)
		{
			cout << res[i] << " ";
		}
		cout << endl;
	}
	return 0;
}


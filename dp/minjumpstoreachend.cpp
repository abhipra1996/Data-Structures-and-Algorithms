#include <bits/stdc++.h>
using namespace std;

/*
        minjumps(start,end)=MIN(minjumps(k,end))
        where k is the number of reachable points from the start
        
        Maxreach= stores maximum reachble index
        Steps= amount of steps we can still take
        jumps= number of jumps to reach maximum reachable point
*/

int minsteps(vector<int > &a)
{
    if(a.size()<=1)
    {
        int k=0;
        return k;
    }
    if(a[0]==0)
    {
        return -1;
    }
    
    int maxreach,step,jump,i;
    maxreach=a[0];
    step=a[0];
    jump=1;
    
    for(i=0;i<a.size();i++)
    {
        if(i==a.size()-1)
        {
            return jump;
        }
        maxreach=max(maxreach,i+a[i]);
        step--;
        if(step==0)
        {
            jump++;
            if(i>=maxreach)
            {
            	return -1;
            }
            step=maxreach-i;
        }
    }
    return -1;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int > a;
	    for(int i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        a.push_back(k);
	    }
	    int ans;
	    ans=minsteps(a);
	    cout << ans << endl;
	}
	return 0;
}

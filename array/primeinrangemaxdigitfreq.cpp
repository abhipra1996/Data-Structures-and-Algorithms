#include <bits/stdc++.h>
using namespace std;

vector<int> findprime(int l,int r)
{
    bool isprime[r+1];
    vector<int> res;
    memset(isprime,true,sizeof(isprime));
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i<=r;i++)
    {
        if(isprime[i]==true)
        {
            if(i>=l && i<=r)
            {
                res.push_back(i);
               //cout << i << " " ;
            }
            for(int j=i*2;j<=r;j=j+i)
            {
               isprime[j]=false;
            }
        }
    }
    //cout << endl;
    return res;
}

int maxdigit(int l, int r)
{
    vector<int> prime;
    int i,j;
    prime=findprime(l,r);
    if(prime.empty())
    {
        return -1;
    }
    map<int,int> m;
    for(i=0;i<=9;i++)
    {
        m[i]=0;
    }
    for(i=0;i<prime.size();i++)
    {
        int dig=0;
        dig=prime[i];
        while(dig>0)
        {
           int tmp=0;
           tmp=dig%10;
           m[tmp]=m[tmp]+1;
           dig=dig/10;
        }
    }
    map<int,int> :: iterator it;
    int max=INT_MIN;
    int res;
    for(it=m.begin();it!=m.end();it++)
    {
        //cout << it->first << " : " << it->second << endl;
        if(it->second >= max)
        {
            max=it->second;
            res=it->first;
        }
    }
    return res;
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int l,r,res=0;
	    cin >> l >> r;
	    res=maxdigit(l,r);
	    cout << res << endl;
	}
	return 0;
}

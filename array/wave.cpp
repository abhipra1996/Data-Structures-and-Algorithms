#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

vector<int> wave(vector<int> &a)
{
    sort(a.begin(),a.end());
    int i;
    for(i=0;i<a.size();i=i+2)
    {
        if(i>0 && a[i]<a[i-1])
        {
            swap(&a[i],&a[i-1]);
        }
        if(i<a.size()-1 && a[i]<a[i+1])
        {
            swap(&a[i],&a[i+1]);
        }
    }
    return a;
}

int main() {
	int t;
	cin >> t ;
	while(t--)
	{
	    int n,i,j;
	    cin >> n;
	    vector<int> num;
	    for(i=0;i<n;i++)
	    {
	        int k;
	        cin >> k;
	        num.push_back(k);
	    }
	    num=wave(num);
	    for(i=0;i<num.size();i++)
	    {
	        cout << num[i] << " ";
	    }
	    cout << endl ;
	}
	return 0;
}

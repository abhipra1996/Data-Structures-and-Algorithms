#include <bits/stdc++.h>
using namespace std;

vector<int> nearlysorted(vector<int> &a,int k)
{
     vector<int> res;
     priority_queue<int,vector<int>,greater<int>> pq;
     for(int i=0;i<a.size();i++)
     {
         pq.push(a[i]);
     }
     for(int i=0;i<a.size();i++)
     {
        res.push_back(pq.top());
        pq.pop();
     }
     return res;
}
/*
vector<int> nearlysortedheap(vector<int> &a,int k)
{
    vector<int> heap(k);
    vector<int> res(a.size());
    int end=a.size()-1;
    int i;
    for(i=0;i<k;i++)
    {
        a[i]=heap[i];
    }
    make_heap(heap.begin(),heap.end());
    for(;i<a.size();i++)
    {
        res[end]=heap.front();
        end--;
        pop_heap(heap.begin(),heap.end());
        heap.push_back(a[i]);
        push_heap(heap.begin(),heap.end());
    }
    while(!heap.empty())
    {
        res[end]=heap.front();
        end--;
        pop_heap(heap.begin(),heap.end());
    }
    return res;
}
*/
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n,k;
	    cin >> n >> k;
	    vector<int> a;
	    for(int i=0;i<n;i++)
	    {
	        int m;
	        cin >> m;
	        a.push_back(m);
	    }
	    a=nearlysorted(a,k);
	    for(int i=0;i<a.size();i++)
	    {
	        cout << a[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}

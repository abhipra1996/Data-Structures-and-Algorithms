#include <bits/stdc++.h>
using namespace std;

int swapbits(int x,int p1,int p2,int n)
{
    unsigned int set1,set2,xor2;
    set1=(x>>p1) & ((1U<<n)-1);
    set2=(x>>p2)  & ((1U<<n)-1) ;
    xor2=set1^set2;
    xor2=(xor2 << p1 ) | (xor2<<p2);
    return x^xor2;
    
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int x,p1,p2,n,sol;
	    cin >> x >> p1 >> p2 >> n;
	    sol=swapbits(x,p1,p2,n);
	    cout << sol << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

unsigned int rightmostset(unsigned int a)
{
	return log2(a & -a)+1;
}


int main()
{
    unsigned int x,res;
	cin >> x;
	res=rightmostset(x);
	cout << res << endl;
	return 0;
} 

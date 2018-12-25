#include<bits/stdc++.h>
using namespace std;

void toh(int n,string from,string to,string aux)
{
	if(n==1)
	{
		cout << "MOVE FROM " << from << "to" << to << "." << endl;
		return;
	}
	toh(n-1,from,aux,to);
	cout << "MOVE FROM " << from << "to" << to << "." << endl;
	toh(n-1,aux,to,from);
}

int main()
{
	int n;
	cin >> n;
	toh(n,"A","C","B");     // source=a , dest=c , aux=b	
}



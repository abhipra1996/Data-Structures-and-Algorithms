#include<bits/stdc++.h>
using namespace std;


void print(vector<int > &a)
{
	for(int i=0;i<a.size();i++)
	{
		cout << a[i] << " " ;
	}
	cout << endl ;
}


vector<int > moveleft(vector<int > &a,int last)
{
	for(int i=0;i<a.size();i++)
	{
		a[i]=a[i+1];
	}
	a[a.size()-1]=last;
	return a;
}

vector<int > rotateone(vector<int > &a,int d)
{
	for(int i=0;i<d;i++)
	{
		int temp;
		temp=a[0];
		a=moveleft(a,temp);
		print(a);
	}
	return a;
}
void reverse(vector<int > &a,int start,int end)
{
	int temp;
	while(start<end)
	{
		temp=a[start];
		a[start]=a[end];
		a[end]=temp;
		start++;
		end--;
	}
}

vector<int > reverserotate(vector<int > &a,int d)
{
	int n;
	n=a.size();
	reverse(a,0,d-1);
	reverse(a,d,n-1);
	reverse(a,0,n-1);
	return a;
}
vector<int > juggle(vector<int > &a,int d)
{
	int size,g,j,k,temp;
	size=a.size();
	g=__gcd(size,d);                             // gcd stl
	for(int i=0;i<g;i++)
	{
		temp=a[i];
		j=i;
		while(1)
		{
			k=j+d;
			if(k>=size)
			{
				k=k-size;                                 //makes k vales smaller for breaking condition
			}
			if(k==i)
			{
				break;
			}
			a[j]=a[k];
			j=k;
		}
		a[j]=temp;
		print(a);
	}
	return a;
}

int main()
{
	int n,i;
	cout << "ENTER SIZE OF ARRAY : ";
	cin >> n;
	cout << "ENTER ELEMENTS OF ARRAY : " <<endl;
	vector<int > a;
	for(i=0;i<n;i++)
	{
		int k;
		cin >> k;
		a.push_back(k);
	}
	int pos;
	cin >> pos;
	//a=rotateone(a,pos);
	//a=juggle(a,pos);
	a=reverserotate(a,pos);
	print(a);
	return 0;
}

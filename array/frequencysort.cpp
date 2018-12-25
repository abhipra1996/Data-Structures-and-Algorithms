#include<bits/stdc++.h>
using namespace std;

struct element
{
    int index;
	int count;
	int num;	
};

bool mycomp(struct element a,struct element b)
{
	return(a.num<b.num);
}

bool mycomp2(struct element a,struct element b)
{
	if(a.count!=b.count)
	{
		return (a.count<b.count);
	}
	else
	{
		return(a.index>b.index);
	}
}

void frequencysort(vector<int > &a)                     // using sorting...sort then count and sort again using count 		O(nlogn)
{
	struct element el[a.size()];
	int i,n,index;
	n=a.size();
	for(i=0;i<n;i++)
	{
		el[i].index=i;
	    el[i].count=0;
		el[i].num=a[i];
	}
	stable_sort(el,el+n,mycomp);            //to maintain the relative order
	el[0].count=1;
	for(i=1;i<n;i++)
	{
		if(el[i].num==el[i-1].num)
		{
			el[i].count+=el[i-1].count+1;
			el[i-1].count=-1;
			el[i].index=el[i-1].index;
		}
		else
		{
			el[i].count=1;
		}
	}
	stable_sort(el,el+n,mycomp2);	
	for(i=n-1,index=0;i>=0;i--)
	{
		if(el[i].index!=-1)
		{
			for(int j=0;j<el[i].count;j++)
			{
				a[index++]=el[i].num;
			}
		}	
	}
	
}

void print(vector<int > &a)
{
	for(int i=0;i<a.size();i++)
	{
		cout << a[i] << " " ;
	}
	cout << endl ;
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
	frequencysort(a);
	print(a);
	return 0;
}

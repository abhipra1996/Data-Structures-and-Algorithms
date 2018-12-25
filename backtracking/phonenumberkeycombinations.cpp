void combi(string A,int curr,string str,int size,vector<string> &res,map<int,string> m)
{
    int i;
    if(curr==size)
    {
        res.push_back(str);
        return;
    }
    string temp;
    temp=m[A[curr]-'0'];
    for(i=0;i<temp.size();i++)
    {
        str[curr]=temp[i];
        combi(A,curr+1,str,size,res,m);
    }
}


vector<string> Solution::letterCombinations(string A) {
   map<int,string> m;
   m[0]="0";
   m[1]="1";
   m[2]="abc";
   m[3]="def";
   m[4]="ghi";
   m[5]="jkl";
   m[6]="mno";
   m[7]="pqrs";
   m[8]="tuv";
   m[9]="wxyz";
   int n;
   n=A.size();
   string str(n,' ');
   vector<string> res;
   string set;
   combi(A,0,str,n,res,m);
   return res;
   
}


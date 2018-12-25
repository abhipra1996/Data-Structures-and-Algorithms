long long int makenum(long long int num,long long int a,bool neg)
{
    long long int ans;
    ans=num*10+a;
    if(ans>=INT_MAX && !neg)
    {
        return INT_MAX;
    }
    else if(ans>=INT_MAX && neg)
    {
        return INT_MIN;
    }
    return ans;
}
int atoi(const string &A) {
    string temp;
    temp=A;
    long long int num=0;
    bool neg=false,pos;
    map<char,long long int> m;
    m['0']=0;
    m['1']=1;
    m['2']=2;
    m['3']=3;
    m['4']=4;
    m['5']=5;
    m['6']=6;
    m['7']=7;
    m['8']=8;
    m['9']=9;
    m['-']=-1;
    m['+']=1;
    for(int i=0;i<A.size();i++)
    {
        if(m.find(temp[i])!=m.end() && m[temp[i]]!=-1 && temp[i]!='+')
        {
            num=makenum(num,m[temp[i]],neg);
            if(num==INT_MAX || num==INT_MIN)
            {
                return num;
            }
        }
        else if(m[temp[i]]==-1)
        {
            neg=true;
        }
        else if(temp[i]=='+')
        {
            pos=true;
        }
        else
        {
            break;
        }
    }
    if(neg)
    {
        num=num * -1 ;
    }
    return num;
}


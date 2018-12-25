struct trienode{
  map<char,struct trienode *> children;
  bool isend;
};

struct trienode* newnode()
{
    struct trienode *node=NULL;
    node=(struct trienode*)malloc(sizeof(struct trienode));
    map<char,struct trienode *> temp;
    for(int i=0;i<26;i++)
    {
        char c;
        c='a'+i;
        //cout << c << " ";
        temp[c]=NULL;
    }
    node->children=temp;
    node->isend=false;
    return node;
}

void insert(struct trienode *root,string str)
{
    int i,len;
    len=str.size();
    struct trienode *temp=NULL;
    temp=root;
    //cout << str << endl;
    for(i=0;i<len;i++)
    {
        if(temp->children[str[i]]==NULL)
        {
            struct trienode *x=new struct trienode();
            temp->children[str[i]]=x;
        }
        temp=temp->children[str[i]];
    }
    temp->isend=true;
   // cout << "insertion done" << endl;
}

bool search(struct trienode *root,string str)
{
    struct trienode *temp=NULL;
    temp=root;
    for(int i=0;i<str.size();i++)
    {
        if(temp->children[str[i]]==NULL)
        {
            return false;
        }
        temp=temp->children[str[i]];
    }
    
    return (temp!=NULL && temp->isend);
}

vector<string> words(string str)
{
    string temp;
    vector<string> res;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!='_' && str[i]!=' ')
        {
            temp=temp+str[i];
        }
        else if(str[i]==' ')
        {
            //continue;
        }
        else
        {
            res.push_back(temp);
            temp.clear();
        }
    }
    res.push_back(temp);
    /*for(int i=0;i<res.size();i++)
    {
        cout << res[i] << ":" << res[i].size() << endl;
    }*/
    return res;
}

bool comp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second > p2.second;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    vector<int> res;
    int i;
    //struct trienode *root=NULL;
    //root=newnode();
    struct trienode *root=new struct trienode();
    vector<string> goodwords;
    goodwords=words(A);
    for(i=0;i<goodwords.size();i++)
    {
        insert(root,goodwords[i]);
    }
    vector<pair<int,int > > cnt;
    for(i=0;i<B.size();i++)
    {
        vector<string> review;
        review=words(B[i]);
        int count=0;
        pair<int,int > p;
        for(int j=0;j<review.size();j++)
        {
            if(search(root,review[j])==true)
            {
                count++;
            }
        
        }
        //cout << count << endl;
        p=make_pair(i,count);
        cnt.push_back(p);
    }
    //cout << "done reviews" << endl;
    stable_sort(cnt.begin(),cnt.end(),comp);
    for(i=0;i<cnt.size();i++)
    {
        res.push_back(cnt[i].first);
    }
    return res;
    
}


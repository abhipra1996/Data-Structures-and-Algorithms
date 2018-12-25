
bool issafe(vector<vector<char > > &board,int row,int col,int n)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i]=='Q')
        {
            return false;
        }
    }
    
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    
    for(i=row,j=col;j>=0 && i<n;i++,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;
}

bool nqueen(vector<vector<char>> &board,int col,int A,vector<vector<string > > &res) 
{
    if(col>=A)
    {
         vector<string> tempboard;
         for(int j=0;j<A;j++)
           {
               string temp;
               for(int k=0;k<A;k++)
               {
                   temp=temp+board[j][k];
               }
               tempboard.push_back(temp);
           }
           res.push_back(tempboard);
    }
    for(int i=0;i<A;i++)
    {
        if(issafe(board,i,col,A))
        {
            board[i][col]='Q';
            
            if(nqueen(board,col+1,A,res))
            {
                return true;
            }
            
            board[i][col]='.';
        }
    }
    return false;
}


vector<vector<string> > solveNQueens(int A) {
    vector<vector<string> > res;
    vector<vector<char > > board(A,vector<char>(A,'.'));
    nqueen(board,0,A,res);
    return res;
}


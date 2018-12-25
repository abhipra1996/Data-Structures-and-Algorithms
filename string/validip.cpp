bool isvalidnumber(char *ip)
{
    while(*ip)
    {
        if(*ip>='0' && *ip<='9')
        {
            (ip)++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int isValid(char *ip)
{
    int dots,num;
    dots=0;
    
    if(ip==NULL)
    {
        return 0;
    }
    
    
    char *ptr;
    ptr=strtok(ip,".");
    if(ptr==NULL)
    {
        return 0;
    }
    while(ptr)
    {
        if(!isvalidnumber(ptr))
        {
            return 0;
        }
        
        num=atoi(ptr);
        if(num>=0 && num <=255)
        {
            ptr=strtok(NULL,".");
            if(ptr!=NULL)
            {
                dots++;
            }
        }
        else
        {
            return 0;
        }
    }
    
    if(dots!=3)
    {
        return 0;
    }
    return 1;
}

//Program to implement the game of tic-tac-toe in the player vs. computer format.
int count(int a[3][3])
{
    int n=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(a[i][j]==3)
                n++;
        }
    }
    return n;
}

int win(int a[3][3])
{
    for(int i=0; i<3; i++)
    {
        if((a[i][0]==1)&&(a[i][1]==1)&&(a[i][2]==1))
            return(1);
        if((a[0][i]==1)&&(a[1][i]==1)&&(a[2][i]==1))
            return(1);
    }
    if((a[0][0]==1)&&(a[1][1]==1)&&(a[2][2]==1))
        return 1;
    if((a[0][2]==1)&&(a[1][1]==1)&&(a[2][0]==1))
        return 1;

    for(int i=0; i<3; i++)
    {
        if((a[i][0]==0)&&(a[i][1]==0)&&(a[i][2]==0))
            return(-1);
        if((a[0][i]==0)&&(a[1][i]==0)&&(a[2][i]==0))
            return(-1);
    }
    if((a[0][0]==0)&&(a[1][1]==0)&&(a[2][2]==0))
        return -1;
    if((a[0][2]==0)&&(a[1][1]==0)&&(a[2][0]==0))
        return -1;
    else
        return 0;
}


int min(int c1[][3],int b);

int max(int c1[][3],int b)
{
    int n=count(c1);
    int v=-100;
    if(win(c1)==0)
    {
        if(n>0)
        {
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                {
                    if(c1[i][j]==3)
                    {
                        c1[i][j]=1;
                        if(min(c1,b)>v)
                            v=min(c1,b-1);
                        c1[i][j]=3;
                    }
                }
        }
        return v*b*b;  //Each result has a 'weight' associated with it. 
    }                  //A closer victory has higher preference.
    else
        return win(c1);
}

 
int min(int c1[][3],int b)
{
    int n=count(c1);

    int v=100;
    if(win(c1)==0)
    {
        if(n>0)
        {
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                {
                    if(c1[i][j]==3)
                    {
                        c1[i][j]=0;
                        if(max(c1,b)<v)
                            v=max(c1,b-1);
                        c1[i][j]=3;
                    }
                }
        }
        return v*b*b;
    }
    else
        return (win(c1));
}

int p(int t[][3])
{
    int n= count(t);
    for(int k=0;; k++)
    {
        n= count(t);
        if(n==0)
            break;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(t[i][j]==3)
                {
                    t[i][j]=1;
                    if(win(t)==1)
                    {
                        //toggle(i,j,t);
                        //display(ai wins);
                        t[i][j]=1;
                        return i*10+j;
                    }
                    t[i][j]=3;
                }
            }
        }

        if((win(t)==0))
        {
            int r=-3,c=-4,val=-1000000;
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                {
                    if(t[i][j]==3)
                    {
                        t[i][j]=1;
                        int w=min(t,n);
                        if(w>val)
                        {
                            val=w;
                            r=i;
                            c=j;
                        }
                        t[i][j]=0;
                        if(win(t)==-1)
                        {
                            t[i][j]=1;
                            return i*10+j;
                        }
                        t[i][j]=3;
                    }
                }
            t[r][c]=1;
            return r*10+c;
        }
    }
    return 1;
}

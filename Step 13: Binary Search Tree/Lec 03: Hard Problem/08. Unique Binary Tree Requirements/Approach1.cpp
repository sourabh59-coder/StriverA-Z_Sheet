bool isPossible(int a,int b)
    {
        if(a==1 && b==2 || a==2 && b==1 || a==2 && b==3 || a==3 && b==2)
            return true;
        else
            return false ;
    }

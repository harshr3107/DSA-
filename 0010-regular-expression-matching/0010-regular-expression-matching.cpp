class Solution {
public:
    
    bool ispossible(string& s,string& p,int i,int j)
    {
       // cout<<"i entered here for "<<i<<" "<<j<<endl;

        if(i==s.length() && j==p.length())
        {
            return true;
        }

        if(j==p.length())
        {
                return false;
        }

        

        if(p.at(j)=='.')
        {

            if((j+1)<p.length() && p.at(j+1)=='*')
            {
                 if(ispossible(s,p,i,j+2)==true)
                {
                    return true;
                }


                int k=i;
                while(k<s.length())
                {
                    if(ispossible(s,p,k+1,j+2)==true)
                    {
                        return true;

                    }
                    
                    k++;

                }

            }else{


            if(ispossible(s,p,i+1,j+1)==true)
            {
                return true;
            }

            }






        }else if((j+1)<p.length() && (p.at(j)>='a' && p.at(j)<='z') && (p.at(j+1)=='*'))
        {

            if(ispossible(s,p,i,j+2)==true)
            {
                return true;
            }




            int k=i;

            while(k<s.length() && s.at(k)==p.at(j))
            {
                if(ispossible(s,p,k+1,j+2)==true)
                {
                    return true;
                }

                k++;


            }
            


        }else{

            if(i<s.length() && (p.at(j)==s.at(i)))
            {
                if(ispossible(s,p,i+1,j+1)==true)
                {
                    return true;
                }

            }else{

                return false;
            }


        }


        return false;

      



    }


    bool isMatch(string s, string p) {

        int i=0;
        int j=0;

        return ispossible(s,p,i,j);
        
    }
};
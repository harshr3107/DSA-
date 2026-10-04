class Solution {
public:
    

    bool checkif(string& s,int i,int open,vector<vector<int>>& dp)
    {
        if(i==s.length())
        {
            return open==0;
        }

        if(dp[i][open]!=-1)
        {
            return dp[i][open];
        }

        if(s.at(i)=='(')
        {
            
            if(checkif(s,i+1,open+1,dp))
            {
                    return dp[i][open]=true;
            }
        }else if(s.at(i)==')')
        {
             if(open<=0)
             {
                return false;
             }

             if(checkif(s,i+1,open-1,dp))
             {
                return dp[i][open]=true;
             }

        }else{

            //we can consider * as nothing

            if(checkif(s,i+1,open,dp))
            {
                return dp[i][open]=true;
            }

            //we can consider * as (

            if(checkif(s,i+1,open+1,dp))
            {
                return dp[i][open]=true;
            }

            //we can consider * as )

            if(open>0)
            {
                 if(checkif(s,i+1,open-1,dp))
                {
                    return dp[i][open]=true;
                }


            }


        }


        return dp[i][open]=false;

    }


    bool checkValidString(string s) {

        int open=0;
        int i=0;
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        return checkif(s,i,open,dp);
        
    }
};
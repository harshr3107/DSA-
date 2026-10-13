class Solution {
public:

    int getans(string& s,int i,vector<int>& dp)
    {
        if(i==s.length())
        {
            return 1;
        }

        


        if(s.at(i)=='0')
        {
            return 0;
        }


        if(dp[i]!=-1)
        {
            return dp[i];
        }

        int m1 = 0;
        int m2 = 0;

        m1 = getans(s,i+1,dp);

        if((i+1)<s.length() && (s.at(i)=='1' || (s.at(i)=='2' && s.at(i+1)>='0' && s.at(i+1)<='6')))
        {
            m2 = getans(s,i+2,dp);
        }


        return dp[i]=m1+m2;

    

    }
   



    int numDecodings(string s) {


        int i=0;
        vector<int> dp(s.length(),-1);
        return getans(s,i,dp);
        
    }
};
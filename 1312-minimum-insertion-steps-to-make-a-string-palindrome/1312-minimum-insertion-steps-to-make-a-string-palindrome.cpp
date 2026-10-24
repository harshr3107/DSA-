class Solution {
public:
    

    int getans(string& s,int i,int j,vector<vector<int>>& dp)
    {
        if(i>=j)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int m1=1e9+7;
        int m2 = 1e9+7;
        int m3 = 1e9+7;

        if(s.at(i)==s.at(j))
        {
            m1=0+getans(s,i+1,j-1,dp);
        }else{

            m2 = 1+getans(s,i+1,j,dp);
            m3 = 1+getans(s,i,j-1,dp);

        }

        return dp[i][j]=min(m1,min(m2,m3));

    }

   

    int minInsertions(string s) {
        int i=0;
        int j=s.length()-1;
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        return getans(s,i,j,dp);




        
    }
};
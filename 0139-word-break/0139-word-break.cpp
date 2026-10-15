class Solution {
public:

   bool checkpossible(string&s,int i,map<string,int>& mp,vector<int>& dp)
   {

       if(i==s.length())
       {
        return true;
       }

       if(dp[i]!=-1)
       {
        return dp[i];
       }


       for(int j=i;j<s.length();j++)
       {
             if(mp.find(s.substr(i,j-i+1))!=mp.end())
             {
                if(checkpossible(s,j+1,mp,dp)==true)
                {
                    return dp[i]=true;
                }
             }
       }


       return dp[i]=false;

   }
   


    bool wordBreak(string s, vector<string>& wd) {

        map<string,int> mp;
        for(auto it: wd)
        {
            mp[it]++;
        }

        int i=0;

        vector<int> dp(s.length(),-1);

        return checkpossible(s,i,mp,dp);
        
    }
};
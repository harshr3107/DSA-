class Solution {
public:
    
    bool checkpossible(string s,string t,map<pair<string,string>,bool>& dp)
    {



        if(s==t)
        {
            return true;
        }

        pair<string,string> h = make_pair(s,t);

        if(dp.find(h)!=dp.end())
        {
            return dp[h];
        }


        if(s.length()!=t.length())
        {
            return dp[h]=false;
        }


       bool ans=false;

       


        for(int i=0;i<s.length()-1;i++)
        {
            string left = s.substr(0,i+1);
            string right = s.substr(i+1);

            

            bool not_swapped = checkpossible(s.substr(0,i+1),t.substr(0,i+1),dp) && checkpossible(s.substr(i+1),t.substr(i+1),dp);

            bool swapped = checkpossible(s.substr(i+1),t.substr(0,right.length()),dp) && checkpossible(s.substr(0,i+1),t.substr(right.length()),dp);

            if(swapped == true || not_swapped==true)
            {
                ans=true;
                break;
            }
        }

        return dp[h]=ans;

    }


    bool isScramble(string s1, string s2) {

            map<pair<string,string>,bool> dp;
   
            return checkpossible(s1,s2,dp);

        
    }
};
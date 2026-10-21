class Solution {
public:
     
    void getall(string&s,map<string,int>& mp,int i,string& cstr,vector<string>& ans)
    {
        if(i==s.length())
        {
            if(cstr.length()!=0)
            {
                ans.push_back(cstr.substr(0,cstr.length()-1));
            }

            return;
        }


        for(int j=i;j<s.length();j++)
        {
            if(mp.find(s.substr(i,j-i+1))!=mp.end())
            {
                string temp=cstr;
                cstr+=s.substr(i,j-i+1);
                cstr+=" ";
                getall(s,mp,j+1,cstr,ans);
                cstr=temp;
            }

        }

        



    }



    vector<string> wordBreak(string s, vector<string>& wd) {

        map<string,int> mp;
        for(auto it: wd)
        {
            mp[it]++;
        }

        vector<string> ans;
        string cstr="";
        int i=0;
        getall(s,mp,i,cstr,ans);

        return ans;



        
    }
};
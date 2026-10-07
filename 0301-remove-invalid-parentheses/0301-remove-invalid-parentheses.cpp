class Solution {
public:
    
    void getall(string& s,int i,int open,string& cstr,vector<string>& ans)
    {
        if(i==s.length())
        {
            if(open==0)
            {
                if(ans.size()==0)
                {
                    ans.push_back(cstr);
                }else if(ans[0].length()==cstr.length())
                {
                        if(find(ans.begin(), ans.end(), cstr) == ans.end()) 
                        {
                            ans.push_back(cstr);
                        }
                }else if(ans[0].length()<cstr.length())
                {
                    ans.clear();
                    ans.push_back(cstr);
                }
            }

            return;

        }

        

        //take this bracket or not

        if(s.at(i)=='(')
        {
            cstr.push_back('(');
            getall(s,i+1,open+1,cstr,ans);
            cstr.pop_back();

            getall(s,i+1,open,cstr,ans);


        }else if(s.at(i)==')'){

            if(open>0)
            {
                cstr.push_back(')');
                getall(s,i+1,open-1,cstr,ans);
                cstr.pop_back();
               
            }

             getall(s,i+1,open,cstr,ans);



        }else{

            cstr.push_back(s.at(i));
            getall(s,i+1,open,cstr,ans);
            cstr.pop_back();





        }
       


    }

    vector<string> removeInvalidParentheses(string s) {
        
        int open=0;
        vector<string> ans;
        string cstr="";
        int i=0;
        getall(s,i,open,cstr,ans);

        return ans;
        
    }
};
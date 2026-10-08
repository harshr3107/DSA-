class Solution {
public:
    string removeOuterParentheses(string s) {

        stack<char> st;
        string ans="";

        for(auto it: s)
        {
            if(it=='(')
            {
                st.push(it);
                if(st.size()!=1)
                {
                    ans+='(';
                }
            }else{

                if(st.size()>1)
                {
                    ans+=")";
                }

                st.pop();

            }

        }



        return ans;


        
    }
};
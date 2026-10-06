class Solution {
public:
    int minAddToMakeValid(string s) {

        int open=0;
        int ans=0;

        for(auto it: s)
        {
            if(it=='(')
            {
                open++;
            }else{

                if(open==0)
                {
                    ans+=1;
                }else{
                    open--;
                }

            }

        }

        return ans+open;
        
    }
};
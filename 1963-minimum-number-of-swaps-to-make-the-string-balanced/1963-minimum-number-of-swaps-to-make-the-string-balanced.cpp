class Solution {
public:
    int minSwaps(string s) {

        int openswap=0;
        int closeswap=0;

        stack<int> st;
        int close=0;

        for(int i=0;i<s.length();i++)
        {
            if(s.at(i)=='[')
            {
                st.push(i);
            }else{

                if(st.empty())
                {
                    st.push(i);
                    close++;
                }else{
                    st.pop();
                }

            }

        }

        return close;
        
    }
};
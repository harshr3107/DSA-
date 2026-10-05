class Solution {
public:
    int scoreOfParentheses(string s) {


        stack<int> st;
        int h=0;
        int ans=0;

        for(auto it: s)
        {
            //cout<<"mai ander aaya for "<<h<<endl;
            //h++;

            if(it=='(')
            {
                st.push(-1);
            }else{

               


                int a=0;

                while(!st.empty() && st.top()!=-1)
                {
                    a+=st.top();
                    st.pop();
                }

                if(st.top()==-1)
                {
                    st.pop();
                    if(a==0)
                    {
                       st.push(1);
                    }else{
                      st.push(2*a);
                    }
                }

            }

        }

        //cout<<"mai bahara aaya payaya\n";



        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }


        return ans;
        
    }
};
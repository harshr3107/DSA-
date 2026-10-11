class Solution {
public:

    void getnextgreatest(vector<int>& nums,vector<int>& nextgreatest)
    {
        int i=nums.size()-1;
        stack<int> st;
        st.push(-1);

        while(i>=0)
        {
            while(st.top()!=-1 && nums[st.top()]>=nums[i])
            {
                st.pop();
            }

            nextgreatest[i]=st.top();
            st.push(i);
            i--;

        }

    }


    void getprevgreatest(vector<int>& nums,vector<int>& prevgreatest)
    {

        int i=0;
        stack<int> st;
        st.push(-1);

        while(i<nums.size())
        {
            while(st.top()!=-1 && nums[st.top()]>=nums[i])
            {
                st.pop();
            }

            prevgreatest[i]=st.top();
            st.push(i);
            i++;

        }

    }


    void display(vector<int>& v)
    {
        for(auto it: v)
        {
            cout<<it<<" ";
        }

        cout<<endl;
    }




    int maximalSquare(vector<vector<char>>& matrix) {

        vector<int> dp(matrix[0].size(),0);
        int ans=0;

        for(int i=0;i<matrix.size();i++)
        {
            

            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[j]+=1;
                }else{
                    dp[j]=0;
                }

            }

            //cout<<"for the value of i = "<<i<<endl;
            //display(dp);

            //now we have the array let us find the square area
            //dp is the square graph

            vector<int> nextgreatest(dp.size(),0);
            vector<int> prevgreatest(dp.size(),0);

            getnextgreatest(dp,nextgreatest);
            getprevgreatest(dp,prevgreatest);

            for(int i=0;i<nextgreatest.size();i++)
            {
                int left = prevgreatest[i]+1;
                int right = nextgreatest[i]==-1?nextgreatest.size()-1:nextgreatest[i]-1;

                int breadth = right-left+1;

                if(breadth>=dp[i])
                {


                    ans=max(ans,dp[i]*dp[i]);
                }

            }

        }


        return ans;
        
    }
};
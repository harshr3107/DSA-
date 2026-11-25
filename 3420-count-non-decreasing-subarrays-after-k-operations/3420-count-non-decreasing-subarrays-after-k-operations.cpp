class Solution {
public:
    // getnextgreatest(nextgreatest,nums);

    void getnextgreatest(vector<int>& nextgreater,vector<int>& nums)
    {
        stack<int> st;
        st.push(-1);
        int i=nums.size()-1;

        while(i>=0)
        {
            while(st.top()!=-1 && nums[st.top()]<=nums[i])
            {
                st.pop();
            }

            nextgreater[i]=st.top();
            st.push(i);
            i--;

        }



    }


    long long getrange(int i,int j,vector<long long>& csum)
    {
        if(i==0)
        {
            return csum[j];
        }

        return csum[j]-csum[i-1];
    }


    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {

      //cumulative sum

      vector<long long> csum(nums.size(),0);
      csum[0]=nums[0];

      for(int i=1;i<nums.size();i++)
      {
        csum[i]=nums[i]+csum[i-1];
      }

      //form range function




      //firststep was finding next greaer element
       vector<int> nextgreatest(nums.size());
       getnextgreatest(nextgreatest,nums);

       //fill operations 


       vector<long long> operations(nums.size()+1,0);
        int n = nums.size()-1;

       for(int i=n;i>=0;i--)
       {
             long long m = nextgreatest[i];
             if(m==-1)
             {
                m=n+1;
             }

             long long lsegment = 1LL*nums[i]*(m-i)-getrange(i,m-1,csum);
             operations[i]=lsegment+operations[m];
          
       }


       //sliding windo maximum

       deque<int> q;
       
       int i=0;
       int j=0;
       long long ans=0;

       while(j<nums.size())
       {

          while(!q.empty() && nums[q.back()]<nums[j])
          {
            q.pop_back();
          }

          q.push_back(j);

          while(i<=j)
          {

            int m = q.front();

            long long oper = (operations[i]-operations[m])+(1LL*(j-m+1)*nums[m])-getrange(m,j,csum);

            if(oper<=k)
            {
                break;
            }

            i++;

            while(q.front()<i)
            {
                q.pop_front();
            }



          }

          ans+=(j-i+1);
          j++;

         

    }



        return ans;
       
        
    }
};
class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {

        int i=0;
        int j=0;
        long long ans=0;


        while(j<nums.size())
        {

             int prev=j-1;

             if(prev >= 0 && nums[prev]-1!=nums[j])
             {
                i=j;
             }

             ans=ans+(j-i+1);

            j++;


        }

        return ans;


    }
};
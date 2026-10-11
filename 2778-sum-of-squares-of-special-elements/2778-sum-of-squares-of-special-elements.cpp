class Solution {
public:
    int sumOfSquares(vector<int>& nums) {

        int ans=0;
        int n = nums.size();

        for(int i=0;i<nums.size();i++)
        {
            if((n%(i+1))==0)
            {
                //cout<<"i entered here for "<<i<<endl;
                ans=ans+pow(nums[i],2);
            }


        }

        return ans;
        
    }
};
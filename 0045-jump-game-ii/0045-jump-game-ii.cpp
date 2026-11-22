class Solution {
public:
    int jump(vector<int>& nums) {


        int ans=0;
        int maxi=0;
        int currentend=0;

        for(int i=0;i<nums.size()-1;i++)
        {
            maxi=max(maxi,nums[i]+i);
            if(currentend==i)
            {
                ans++;
                currentend=maxi;

            }
            
        }

        return ans;
        
    }
};
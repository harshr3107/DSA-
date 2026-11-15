class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> mp;
        mp[0]=-1;

        int ans=0;
        int csum=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                csum--;
            }else{
                csum++;
            }

            if(mp.find(csum)!=mp.end())
            {
                ans=max(ans,i-mp[csum]);
                
            }else{
                mp[csum]=i;
            }



        }

        return ans;
        
    }
};
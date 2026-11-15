class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

            map<int,int> mp;
            mp[0]=1;
            int ans=0;
            int csum=0;

           for(int i=0;i<nums.size();i++)
           {
                 csum+=nums[i];

                 int req = csum-goal;

                 if(mp.find(req)!=mp.end())
                 {
                    ans+=mp[req];
                 }

                 mp[csum]++;
              

           }

           return ans;
        
    }
};
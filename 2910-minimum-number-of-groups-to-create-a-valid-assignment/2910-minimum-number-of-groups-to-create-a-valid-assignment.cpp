class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {

        

        map<int,int> mp;

        for(int i=0;i<balls.size();i++)
        {
            mp[balls[i]]++;
        }

        int mini=INT_MAX;

        for(auto it: mp)
        {
            mini=min(mini,it.second);

        }


           for (int small = mini; small >= 1; small--) {
            int maxi = small + 1;
            int ans = 0;
            bool valid = true;

            for (const auto& it : mp) {
                int freq = it.second;
                int groups = (freq+maxi-1)/maxi;

                if (groups * small > freq) {
                    valid = false;
                    break;
                }

                ans += groups;
            }

            if (valid) {
                return ans;
            }
        }

        return -1;
       

       

        
        
    }
};
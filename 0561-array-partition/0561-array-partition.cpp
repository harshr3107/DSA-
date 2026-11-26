class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        priority_queue<int> pq;

        for(auto it: nums)
        {
            pq.push(it);
        }

        int ans=0;

        while(!pq.empty())
        {
            pq.pop();
            ans+=pq.top();
            pq.pop();

        }

        return ans;


        
    }
};
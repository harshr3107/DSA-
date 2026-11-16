class Solution {
public:
    
    void display(vector<int>& h)
    {
        for(auto it: h)
        {
            cout<<it<<" ";
        }

        cout<<endl;

    }

    int triangularSum(vector<int>& nums) {

        while(nums.size()!=1)
        {
            vector<int> h;

            for(int i=1;i<nums.size();i++)
            {
                h.push_back((nums[i]+nums[i-1])%10);
            }

            //display(h);

            nums=h;

        }

        return nums[0];
        
    }
};